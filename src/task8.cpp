#include "task8.h"
#include "dynamic.h"
#include "input.h"
#include <limits>

int64_t f(int64_t n)
{
	if (n % 2 == 1)
		return n;

	for (; n % 2 == 0; n >>= 1);
	return n;
}

int64_t task8(std::istream& _In, std::ostream& _Out)
{
	int n;
	if (!read_number(_In, n))
	{
		_Out << "Incorrect input data" << std::endl;
		return std::numeric_limits<int64_t>::min();
	}

	if (n <= 0)
	{
		_Out << "Incorrect value" << std::endl;
		return std::numeric_limits<int64_t>::min();
	}

	int64_t result = 0;
	for (int64_t i = 1; i <= n; i++)
		result += f(i);

	return result;
}