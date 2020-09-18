#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

// #include "Config.h"

const int numbers_in_string = 4;

typedef std::vector<std::string> vect1String;
typedef std::vector<std::vector<std::string>> vect2String;
/*
int versionMin();
int versionMaj();
int versionPatch();
*/
bool ip_pool_compare(const vect1String& First, const vect1String& Second);
vect1String split(const std::string& str, char d);

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



