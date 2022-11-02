#pragma once

#include <iostream>

struct FindResult
{
	int value;
	size_t index;
};

FindResult find_min_in_array(std::istream& _In, std::ostream& _Out);