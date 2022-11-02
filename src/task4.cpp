#include "task4.h"
#include "dynamic.h"
#include "input.h"

#include <limits>

Task4Result task4(std::istream& _In, std::ostream& _Out)
{
	int n, m;

	if (!read_dim(_In, n, m))
	{
		_Out << "Incorrect dimension value" << std::endl;
		return Task4Result{ nullptr, 0u };
	}

	float** matrix = new float* [n];
	float* buf = new float[n * m];
	for (int i = 0; i < n; i++)
		matrix[i] = buf + i * m;

	bool readed = true;
	for (int i = 0; i < n; i++)
		readed &= read_array(_In, matrix[i], m);

	if (!readed)
	{
		delete[] buf;
		delete[] matrix;

		_Out << "Incorrect matrix data:" << std::endl;
		return Task4Result{ nullptr, 0u };
	}

	Task4Result result{ alloc_array(n * m * 2), 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (fabs(matrix[i][j]) < std::numeric_limits<float>::epsilon())
			{
				result.indices[result.size * 2 + 0] = i;
				result.indices[result.size * 2 + 1] = j;
				result.size++;
			}
		}
	}

	float** tmatrix = new float* [m];
	float* tbuf = new float[n * m];
	for (int i = 0; i < m; i++)
		tmatrix[i] = tbuf + i * n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmatrix[j][i] = matrix[i][j];

	for (int i = 0; i < m; i++)
	{
		bool f = true;
		for (int j = 0; j < n; j++)
			_Out << (f ? (f = false, "") : ", ") << tmatrix[i][j];
		_Out << std::endl;
	}

	delete[] tbuf;
	delete[] tmatrix;

	delete[] buf;
	delete[] matrix;

	return result;
}