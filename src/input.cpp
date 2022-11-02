#include "input.h"

bool read_number(std::istream& _In, int& _Value)
{
	constexpr size_t str_max_size = 256;
	char str[str_max_size];

	_In >> str;

	_Value = 0;
	for (auto it = str;
		it != str + str_max_size && *it != 0;
		it++)
	{
		if (*it < '0' || *it > '9')
			return false;

		_Value *= 10;
		_Value += *it - '0';
	}

	return true;
}

bool read_array(std::istream& _In, int* _Array, size_t _Size)
{
	bool readed = true;

	for (auto it = _Array; it != _Array + _Size; it++)
		readed &= read_number(_In, *it);

	return readed;
}

bool read_number(std::istream& _In, float& _Value)
{
	constexpr size_t str_max_size = 512;
	char str[str_max_size];

	_In >> str;

	_Value = 0.f;
	float ap_coeff = 0.1f;
	bool after_dot = false;
	for (auto it = str;
		it != str + str_max_size && *it != 0;
		it++)
	{
		if (*it == '.')
		{
			if (after_dot)
				return false;

			after_dot = true;
			++it;
			if (it == str + str_max_size || *it == 0)
				break;
		}

		if (*it < '0' || *it > '9')
			return false;

		if (!after_dot)
		{
			_Value *= 10;
			_Value += *it - '0';
		}
		else
		{
			_Value += (*it - '0') * ap_coeff;
			ap_coeff *= 0.1f;
		}
	}

	return true;
}

bool read_array(std::istream& _In, float* _Array, size_t _Size)
{
	bool readed = true;

	for (auto it = _Array; it != _Array + _Size; it++)
		readed &= read_number(_In, *it);

	return readed;
}