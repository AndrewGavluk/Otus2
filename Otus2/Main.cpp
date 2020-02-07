#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int numbers_in_string = 4;

typedef std::vector<std::string> vect1String;
typedef std::vector<std::vector<std::string>> vect2String;

vect1String split(const std::string& str, char d)
{
	vect1String r;

	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos)
	{
		r.push_back(str.substr(start, stop - start));

		start = stop + 1;
		stop = str.find_first_of(d, start);
	}

	r.push_back(str.substr(start));

	return r;
}

bool ip_pool_compare(const vect1String& First, const vect1String& Second)
{

	for (uint8_t i = 0; i < numbers_in_string; ++i)
	{
		if (std::stoi(First[i]) > std::stoi(Second[i]))
			return true;
		else if (std::stoi(First[i]) < std::stoi(Second[i]))
			return false;
	}

	return false;
}

template<typename Comparator>
void show(vect2String ip_pool,
	Comparator allowPrint,
	uint8_t firstNumb,
	uint8_t secondNumb)
{
	for (auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
	{
		if (allowPrint(ip, firstNumb, secondNumb))
		{
			for (auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
			{
				if (ip_part != ip->cbegin())
				{
					std::cout << ".";
				}
				std::cout << *ip_part;
			}
			std::cout << std::endl;
		}
	}
}



bool anyOketEql(const vect2String::const_iterator& iter, const uint8_t& firstNumb, const uint8_t& secondNumb = 0)
{
	return ((std::stoi(iter[0][0]) == firstNumb) ||
		(std::stoi(iter[0][1]) == firstNumb) ||
		(std::stoi(iter[0][2]) == firstNumb) ||
		(std::stoi(iter[0][3]) == firstNumb));
}



int main(int argc, char const* argv[])
{
	try
	{
		std::ifstream fin("Test.tsv");

		vect2String ip_pool;

		for (std::string line; std::getline(fin, line);)
		{
			vect1String v = split(line, '\t');
			ip_pool.push_back(split(v.at(0), '.'));
		}

		std::sort(ip_pool.begin(), ip_pool.end(), ip_pool_compare);

		auto constTrue = [](const vect2String::const_iterator& iter, 
								const uint8_t& firstNumb, 
								const uint8_t& secondNumb) 
							{return true; };
		show(ip_pool, constTrue, 0, 0);

		uint8_t firstNumber = 1;
		auto firstOketEql = [](const vect2String::const_iterator& iter, 
									const uint8_t& firstNumb, 
									const uint8_t& secondNumb) 
								{return std::stoi(iter[0][0]) == firstNumb; };
		show(ip_pool, firstOketEql, firstNumber, 0);

		firstNumber = 46;
		uint8_t secondNumber = 70;
		auto firstTwoOketEql = [](const vect2String::const_iterator& iter,
									const uint8_t& firstNumb,
									const uint8_t& secondNumb)
							{return  ((std::stoi(iter[0][0]) == firstNumb) && 
										(std::stoi(iter[0][1]) == secondNumb));};
		show(ip_pool, firstTwoOketEql, firstNumber, secondNumber);
		
		auto anyOketEql = [](const vect2String::const_iterator& iter,
								const uint8_t& firstNumb,
								const uint8_t& secondNumb)
							{return ((std::stoi(iter[0][0]) == firstNumb) ||
										(std::stoi(iter[0][1]) == firstNumb) ||
										(std::stoi(iter[0][2]) == firstNumb) ||
										(std::stoi(iter[0][3]) == firstNumb)); };
		show(ip_pool, anyOketEql, firstNumber, 0);

	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
