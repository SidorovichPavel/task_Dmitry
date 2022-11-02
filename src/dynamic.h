#pragma once

int* alloc_array(int n);

void free_array(int* _Array);

int** alloc_matrix(int n, int m);

void free_matrix(int** _Matrix);

#ifdef _DEBUG
#include <stdint.h>
void show(int* _Array, int64_t n);
void show(int** _Matrix, int n, int m);
#endif