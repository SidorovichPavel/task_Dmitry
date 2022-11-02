#pragma once

struct Task4Result
{
	int* indices;
	size_t size;
};

#include <iostream>

Task4Result task4(std::istream& _In, std::ostream& _Out);