#pragma once

#include <iostream>

struct Task3Result
{
	int* array;
	size_t size;
	int64_t mult;
};

Task3Result task3(std::istream& _In, std::ostream& _Out);

void clear(Task3Result& _Task3Res);