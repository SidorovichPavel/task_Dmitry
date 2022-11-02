#pragma once

#include <iostream>

bool read_number(std::istream& _In, int& _Value);

bool read_array(std::istream& _In, int* _Array, size_t _Size);

bool read_number(std::istream& _In, float& _Value);

bool read_array(std::istream& _In, float* _Array, size_t _Size);

bool read_dim(std::istream& _In, int& _N);

bool read_dim(std::istream& _In, int& _N, int& _M);