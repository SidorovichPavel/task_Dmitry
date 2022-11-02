#include "testing.h"

#include <iostream>
#include <fstream>

bool run3test()
{
	std::fstream fin("test3_unit_tests.txt");
	if (!fin.is_open())
	{
		std::cout << "Cannot open file" << std::endl;
		return false;
	}

	int array[10]{};
	int size;
	int64_t mult;
	bool total_complite = true;

	for (auto i = 1; i <= 3; i++)
	{
		bool complited = true;
		mult = 1;
		fin >> size;
		for (auto j = 0; j < size; j++)
		{
			fin >> array[j];
			mult *= array[i];
		}

		auto res = task3(fin, std::cout);

		complited &= res.size == size;
		complited &= res.mult == mult;

		auto length = res.size < size ? res.size : size;
		for (auto j = 0; j < length; j++)
			complited &= res.array[j] == array[j];

		clear(res);

		if (complited)
			std::cout << "Test " << i << " complited" << std::endl;
		else
			std::cout << "Test " << i << " complited" << std::endl;

		total_complite &= complited;
	}


}