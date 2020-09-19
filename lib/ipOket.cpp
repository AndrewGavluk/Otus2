#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
#include "ipOket.h"


std::ostream& operator<< (std::ostream& out, const QuaterByteAdress& StringAdress)
{

	out << (StringAdress.ip4_adress >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET1_SIZE >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET2_SIZE >> OKET3_SIZE) << '.';
	out << (StringAdress.ip4_adress << OKET3_SIZE >> OKET3_SIZE) << std::endl;

	return out;
}

QuaterByteAdress::QuaterByteAdress(std::string in)
{
	ip4_adress = 0;

	// reading oket by oket
	// i - oket iterator
	// j - char iterator
	for (uint8_t i = 0, j=0, buff=0; i < numbers_in_ip4address; ++i)
		if (in[j]== '.' || in[j]=='\t' || in[j] == '\n')
		{
			ip4_adress = ip4_adress << OKET_SIZE_IN_BITS;
			ip4_adress += buff;
			buff = 0;
			if (in[j]=='\t' || in[j] == '\n')
				break;
		}
		else
			if (std::isdigit(in[j]))
				buff += in[j] - '0';
			else
				std::cerr << "BitAddress.cpp(43), undef symbol while parsing";
}

bool QuaterByteAdress::operator < (QuaterByteAdress const& other)
{
	return ip4_adress < other.ip4_adress;
}

bool QuaterByteAdress::check_mask(uint8_t mask, OKET_SIZE shift)
{
	return mask==((ip4_adress << (OKET3_SIZE-shift)) >> (OKET3_SIZE-shift));
}
