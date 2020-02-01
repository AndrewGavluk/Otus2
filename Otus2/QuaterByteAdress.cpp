#include "QuaterByteAdress.hpp"
#include "Config.h"

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



int versionPatch()
{
	return VERSION_PATCH;
}

int versionMin()
{
	return VERSION_MIN;
}

int versionMaj()
{
	return VERSION_MAJ;
}