#include <algorithm>
#include <iostream>
#include <fstream>
#include <functional>
#include <vector>

#include "../lib/ipOket.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

void show(std::vector<Ip4Okets> AdressList)
{
	for (auto& i : AdressList)
		std::cout << i;
}

void filter(std::vector<Ip4Okets> AdressList, std::function<bool (Ip4Okets&)> predicate)
{
	for (auto& i : AdressList)
		if (predicate(std::ref(i)))
			std::cout << i;
}

int main(int argc, char const* argv[])
{
	UNUSED (argc);
	UNUSED (argv);
	try
	{	
		//std::ifstream fin(argv[1]);
		std::vector<Ip4Okets> AdressList;
		for (std::string line; std::getline(std::cin, line); AdressList.emplace_back(std::ref(line)));
		std::sort(AdressList.rbegin(), AdressList.rend());
		show(AdressList);
		
		filter(AdressList, [](Ip4Okets& i) { return i.check_mask(1, OKET3);});
		filter(AdressList, [](Ip4Okets& i) { return i.check_mask(46, OKET3) && i.check_mask(70, OKET2); });
		filter(AdressList, [](Ip4Okets& i) { return i.check_mask(46, OKET3) || i.check_mask(46, OKET2) 
														|| i.check_mask(46, OKET1) || i.check_mask(46, OKET0); });
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << e.what() << std::endl;
	}

	return 0;
}

