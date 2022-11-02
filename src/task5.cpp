#include "task5.h"
#include "dynamic.h"
#include "input.h"

Task5Result task5(std::istream& _In, std::ostream& _Out)
{
	int n, m;

	if (!read_dim(_In, n, m))
	{
		_Out << "Incorrect dimension value" << std::endl;
		return Task5Result{ nullptr,0u,0 };
	}

	auto matrix = alloc_matrix(n, m);

	bool readed = true;
	for (int i = 0; i < n; i++)
		readed &= read_array(_In, matrix[i], m);

	if (!readed)
	{
		free_matrix(matrix);

		_Out << "Incorrect matrix data:" << std::endl;
		return Task5Result{ nullptr,0u,0 };
	}

	Task5Result result{ alloc_array(n * m), 0u, 0 };

	for (int j = 0; j < m; j += 2)
		for (int i = 0; i < n; i++)
			if (matrix[i][j] % 2)
				result.arithm_mean += result.array[result.size++] = matrix[i][j];
	result.arithm_mean /= static_cast<float>(result.size);

	free_matrix(matrix);

	return result;
}

void clear(Task5Result& _Task)
{
	free_array(_Task.array);
}