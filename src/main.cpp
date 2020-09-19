#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "../lib/ipOket.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

void show(std::vector<QuaterByteAdress> AdressList)
{
	UNUSED (AdressList);
}

int main(int argc, char const* argv[])
{
	UNUSED (argc);
	try
	{	
		std::ifstream fin(argv[1]);
		std::vector<QuaterByteAdress> AdressList;
		for (std::string line; std::getline(fin, line); AdressList.emplace_back(line));
		std::sort(AdressList.begin(), AdressList.end());
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}

