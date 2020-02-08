#include <algorithm>
#include <iostream>
#include <fstream>

#include "QuaterByteAdress.hpp"

#define UNUSED(expr) do { (void)(expr); } while (0)

template<typename Comparator>
void show(vect2String ip_pool,
	Comparator allowPrint,
	uint8_t firstNumb,
	uint8_t secondNumb)
{
	UNUSED(firstNumb);
	UNUSED(secondNumb);

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

int main(int argc, char const* argv[])
{
	try
	{
		std::string filename("Test.tsv");
		if (argc >= 2)
		{
			std::string filename(argv[1]);
		}
		std::ifstream fin(filename);

		vect2String ip_pool;

		for (std::string line; std::getline(fin, line);)
		{
			vect1String v = split(line, '\t');
			ip_pool.push_back(split(v.at(0), '.'));
		}

		std::sort(ip_pool.begin(), ip_pool.end(), ip_pool_compare);

		auto constTrue = [](const vect2String::const_iterator& iter, const uint8_t& firstNumb, const uint8_t& secondNumb) 
							{
								UNUSED(iter);
								UNUSED(firstNumb);
								UNUSED(secondNumb);
								return true; 
							};
		show(ip_pool, constTrue, 0, 0);

		uint8_t firstNumber = 1;
		auto firstOketEql = [](const vect2String::const_iterator& iter, const uint8_t& firstNumb, const uint8_t& secondNumb) 
								{
									UNUSED(secondNumb);
									return std::stoi(iter[0][0]) == firstNumb; 
								};
		show(ip_pool, firstOketEql, firstNumber, 0);

		firstNumber = 46;
		uint8_t secondNumber = 70;
		auto firstTwoOketEql = [](const vect2String::const_iterator& iter, const uint8_t& firstNumb, const uint8_t& secondNumb)
								{
									return  ((std::stoi(iter[0][0]) == firstNumb) && 
											(std::stoi(iter[0][1]) == secondNumb));
								};
		show(ip_pool, firstTwoOketEql, firstNumber, secondNumber);
		
		auto anyOketEql = [](const vect2String::const_iterator& iter,
								const uint8_t& firstNumb,
								const uint8_t& secondNumb)
							{
								UNUSED(secondNumb); 
								return ((std::stoi(iter[0][0]) == firstNumb) ||
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
