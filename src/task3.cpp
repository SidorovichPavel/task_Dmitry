#include "task3.h"
#include "dynamic.h"
#include "input.h"

#include <limits>

void clear(Task3Result& _Task3Res)
{
	free_array(_Task3Res.array);
}

Task3Result parse_matrix(std::istream& _In, std::ostream& _Out)
{
	int n, m;

	if (!read_dim(_In, n, m))
	{
		_Out << "Incorrect dimension value" << std::endl;
		return Task3Result{ nullptr, 0u, 0 };
	}

	auto matrix = alloc_matrix(n, m);

	bool readed = true;
	for (int i = 0; i < n; i++)
		readed &= read_array(_In, matrix[i], m);

	if (!readed)
	{
		free_matrix(matrix);
		_Out << "Incorrect matrix data" << std::endl;
		return Task3Result{ nullptr, 0u, 0 };
	}

#ifdef _DEBUG
	show(matrix, n, m);
#endif

	int k = (n < m) ? n : m;

	Task3Result pr{ alloc_array(k), 0u, 1 };

	for (int i = 0; i < k; i++)
		if (matrix[i][i] % 2 == 0)
			pr.mult *= pr.array[pr.size++] = matrix[i][i];

	free_matrix(matrix);

	return pr;
}