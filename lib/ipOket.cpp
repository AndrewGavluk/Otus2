#include <iostream>
#include <cstdint>
#include <cctype>
#include <vector>
#include <string>
#include <cmath>
#include "ipOket.h"


std::ostream& operator<< (std::ostream& out, const Ip4Okets& StringAdress)
{

	out << (StringAdress.ip4_adress >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET1_SIZE >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET2_SIZE >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET3_SIZE >> OKET3_SIZE) << std::endl;

	return out;
}

Ip4Okets::Ip4Okets(const std::string & in)
{
	ip4_adress = 0;

	// reading oket by oket
	// i - oket iterator
	// j - char iterator
	for (uint8_t i = 0, buff = 0; true; ++i)
		if (in[i] == '.' || in[i] == '\t' || in[i] == '\n')
		{
			ip4_adress = ip4_adress << OKET_SIZE_IN_BITS;
			ip4_adress += buff;
			buff = 0;
			if (in[i] == '\t' || in[i] == '\n')
				break;
		}
		else
			if (std::isdigit(in[i]))
			{
				buff *= 10;
				buff += in[i] - '0';
			}
			else
				std::cerr << "BitAddress.cpp(43), undef symbol while parsing";
}

bool operator < (Ip4Okets const& a, Ip4Okets const& b)
{
	return a.ip4_adress < b.ip4_adress;
}

bool Ip4Okets::check_mask(const uint8_t & mask, const uint8_t & shift)
{
	return mask==((ip4_adress << (OKET3_SIZE-shift)) >> (OKET3_SIZE));
}
