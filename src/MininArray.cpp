#include "MinInArray.h"
#include "dynamic.h"
#include "input.h"

int* recursive_min(int* _First, int* _Last)
{
	if (_Last - _First == 1)
		return _First;
	else
	{
		auto dist = _Last - _First;
		auto mid = _First + dist / 2;

		//show(_First, mid - _First);
		//show(mid, _Last - mid);

		auto a = recursive_min(_First, mid);
		auto b = recursive_min(mid, _Last);
		return (*a < *b) ? a : b;
	}
}

FindResult find_min_in_array(std::istream& _In, std::ostream& _Out)
{
	int n;
	if (!read_number(_In, n))
	{
		_Out << "Incorrect array dimention data" << std::endl;
		return FindResult{ std::numeric_limits<int>::min(), std::numeric_limits<size_t>::max() };
	}

	if (!n)
	{
		_Out << "Find min in array function: invalid dimension value" << std::endl;
		return FindResult{ std::numeric_limits<int>::min(), std::numeric_limits<size_t>::max() };
	}

	auto array = alloc_array(n);

	if (!read_array(_In, array, n))
	{
		free_array(array);
		_Out << "Incorrect array data" << std::endl;
		return FindResult{ std::numeric_limits<int>::min(), std::numeric_limits<size_t>::max() };
	}

#ifdef _DEBUG
	show(array, n);
#endif

	auto it = recursive_min(array, array + n);
	FindResult result{ *it, 0u };
	result.index = it - array;

	free_array(array);

	return result;
}