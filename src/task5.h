#pragma once

#include <iostream>

struct Task5Result
{
	int* array;
	size_t size;
	float arithm_mean;
};

void clear(Task5Result& _Task);


Task5Result task5(std::istream& _In, std::ostream& _Out);