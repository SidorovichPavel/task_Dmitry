#pragma once

#include <iostream>

struct Task1Result
{
	bool is_complited;
	int value;
};

Task1Result find_max_in_matrix(std::istream& _In, std::ostream& _Out);