#include "dynamic.h"

int* alloc_array(int n)
{
	return new int[n];
}

void free_array(int* _Array)
{
	delete[] _Array;
}

int** alloc_matrix(int n, int m)
{
	int* buf = new int[n * m];
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = buf + m * i;

	return matrix;
}

void free_matrix(int** _Matrix)
{
	auto buf = _Matrix[0];
	delete[] buf;
	delete[] _Matrix;
}

#ifdef _DEBUG

#include <iostream>

void show(int* _Array, int64_t n)
{
	std::cout << "---------------Array---------------" << std::endl;

	bool f = true;
	for (int64_t i = 0; i < n; ++i)
		std::cout << (f ? (f = false, "") : ", ") << _Array[i];
	std::cout << std::endl;

	std::cout << "-----------------------------------" << std::endl;
}

void show(int** _Matrix, int n, int m)
{
	std::cout << "--------------matrix---------------" << std::endl;

	for (int i = 0; i < n; ++i)
	{
		bool f = true;
		for (int j = 0; j < m; ++j)
			std::cout << (f ? (f = false, "") : ", ") << _Matrix[i][j];
		std::cout << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;
}
#endif