#include "maxinmatrix.h"
#include "dynamic.h"
#include "input.h"

#include <iostream>
#include <limits>



Task1Result find_max_in_matrix(std::istream& _In, std::ostream& _Out)
{
	int n, m;
	if (!read_number(_In, n) || !read_number(_In, m))
	{
		_Out << "Incorrect input dimention data" << std::endl;
		return Task1Result{ false, std::numeric_limits<int>::min() };
	}

	if (!n || !m)
	{
		_Out << "Invalid dimension value" << std::endl;
		return Task1Result{ false, std::numeric_limits<int>::min() };
	}

	auto X = new int[n];
	if (!read_array(_In, X, n))
	{
		delete[] X;
		_Out << "Incorrect input X array data" << std::endl;
		return Task1Result{ false, std::numeric_limits<int>::min() };
	}

	auto Y = new int[m];

	if (!read_array(_In, Y, m))
	{
		delete[] Y;
		delete[] X;
		_Out << "Incorrect input Y array data" << std::endl;
		return Task1Result{ false, std::numeric_limits<int>::min() };
	}

	//можно организовать поиск в первом же цикле присвоив в max X[0]*Y[0]
	auto matrix = alloc_matrix(n, m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			matrix[i][j] = X[i] * Y[j];

#ifdef _DEBUG
	show(matrix, n, m);
#endif

	int max = matrix[0][0];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (matrix[i][j] > max)
				max = matrix[i][j];

	free_matrix(matrix);

	delete[] Y;
	delete[] X;

	return Task1Result{ true, max };
}