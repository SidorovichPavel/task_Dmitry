#include "maxinmatrix.h"
#include "dynamic.h"
#include "input.h"

void run_task1(std::istream& _In, std::ostream& _Out)
{
    int n, m;

    if (!eread_dim(_In, n, m, _Out, "Incorrect dimension value"))
        return;

    auto X = new int[n];
    if (!eread_array(_In, X, n, _Out, "Incorrect input X array data"))
    {
        delete[] X;
        return;
    }

    auto Y = new int[m];

    if (!eread_array(_In, Y, m, _Out, "Incorrect input X array data"))
    {
        delete[] X;
        delete[] Y;
        return;
    }

    auto res = find_max_in_matrix(X, n, Y, m);
    _Out << "task 1 result: " << res << std::endl;

    delete[] Y;
    delete[] X;
}

int find_max_in_matrix(int* X, int n, int* Y, int m)
{
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

	return max;
}