#include "QuaterByteAdress.hpp"

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

bool anyOketEql(const vect2String::const_iterator& iter, const uint8_t& firstNumb, const uint8_t& secondNumb = 0)
{
	return ((std::stoi(iter[0][0]) == firstNumb) ||
		(std::stoi(iter[0][1]) == firstNumb) ||
		(std::stoi(iter[0][2]) == firstNumb) ||
		(std::stoi(iter[0][3]) == firstNumb));
}

std::ostream& operator<< (std::ostream& out, const QuaterByteAdress& StringAdress)
{
	out << StringAdress.m_first;
	out << StringAdress.m_second;
	out << StringAdress.m_third;
	out << StringAdress.m_forth;

	return out;
}

std::istream& operator>> (std::istream& in, QuaterByteAdress& StringAdress)
{
	in >> StringAdress.m_first;
	in >> StringAdress.m_second;
	in >> StringAdress.m_third;
	in >> StringAdress.m_forth;

	return in;
}

bool QuaterByteAdress::operator > (QuaterByteAdress const& other)
{

	return ((m_first > other.m_first) ||
		((m_first = other.m_first) && (m_second > other.m_second)) ||
		((m_first = other.m_first) && (m_second = other.m_second) && (m_third > other.m_third)) ||
		((m_first = other.m_first) && (m_second = other.m_second) && (m_third = other.m_third) && (m_forth > other.m_forth)));

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


int versionPatch()
{
	return PROJECT_VERSION_PATCH;
}

int versionMin()
{
	return PROJECT_VERSION_MINOR;
}

int versionMaj()
{
	return PROJECT_VERSION_MAJOR;
}