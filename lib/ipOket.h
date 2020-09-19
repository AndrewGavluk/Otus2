#pragma once

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>


// #include "Config.h"
struct QuaterByteAdress;

constexpr int numbers_in_ip4address = 4;
constexpr int OKET_SIZE_IN_BITS = 8;
constexpr int OKET4_SIZE = OKET_SIZE_IN_BITS * numbers_in_ip4address;
enum OKET_SIZE{
	OKET0_SIZE = 0,
	OKET1_SIZE = OKET_SIZE_IN_BITS,
	OKET2_SIZE = OKET_SIZE_IN_BITS*2,
	OKET3_SIZE = OKET_SIZE_IN_BITS*3
};

struct QuaterByteAdress
{
	QuaterByteAdress(std::string);
	friend std::ostream& operator<< (std::ostream& out, const QuaterByteAdress& point);
	bool operator  < (QuaterByteAdress const& b);

	bool check_mask (uint8_t mask, OKET_SIZE shift);

	uint32_t ip4_adress;
};



