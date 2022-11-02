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

bool read_dim(std::istream& _In, int& _N)
{
	return read_number(_In, _N) && _N;
}

bool read_dim(std::istream& _In, int& _N, int& _M)
{
	return (read_number(_In, _N) && read_number(_In, _M)) && (_N && _M);
}

bool eread_number(std::istream& _In, int& _Value, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_number(_In, _Value);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}
bool eread_array(std::istream& _In, int* _Array, size_t _Size, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_array(_In, _Array, _Size);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}

bool eread_number(std::istream& _In, float& _Value, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_number(_In, _Value);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}
bool eread_array(std::istream& _In, float* _Array, size_t _Size, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_array(_In, _Array, _Size);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}

bool eread_dim(std::istream& _In, int& _N, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_dim(_In, _N);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}
bool eread_dim(std::istream& _In, int& _N, int& _M, std::ostream& _Out, const char* _ErrMsg)
{
	auto res = read_dim(_In, _N, _M);
	if (!res)
		_Out << _ErrMsg << std::endl;
	return res;
}