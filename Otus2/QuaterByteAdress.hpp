#pragma once

#include <cstdint>
#include <iostream>

enum MyEnum
{
	Oket1,
	Oket2,
	Oket3,
	Oket4,
	AnyOket
};

struct QuaterByteAdress
{

	friend std::ostream& operator<< (std::ostream& out, const QuaterByteAdress& point);
	friend std::istream& operator>> (std::istream& in, QuaterByteAdress& point);

	bool operator  > (QuaterByteAdress const& b);

	uint8_t m_first;
	uint8_t m_second;
	uint8_t m_third;
	uint8_t m_forth;
};


int versionPatch();
int versionMin();
int versionMaj();