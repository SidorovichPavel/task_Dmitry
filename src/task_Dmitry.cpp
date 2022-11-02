#include <iostream>
#include <fstream>
#include <string>

#include "maxinmatrix.h"
#include "MinInArray.h"
#include "task3.h"
#include "task4.h"

int main()
{
    std::ifstream fin("input.txt");

    auto max = find_max_in_matrix(fin, std::cout);
    std::cout << "Max element in matrix: " << max.value << std::endl;

    auto min = find_min_in_array(fin, std::cout);
    std::cout << "Min element in array: " << min.value
        << ", index: " << min.index << std::endl;

    auto t3res = parse_matrix(fin, std::cout);
    if (t3res.array)
    {
        std::cout << "Dynamic array as matrix parse result:" << std::endl;
        bool f = true;
        for (auto it = t3res.array;
            it != t3res.array + t3res.size;
            ++it)
            std::cout << (f ? (f = false, "") : ", ") << *it;
        std::cout << std::endl;
        std::cout << "multiplication of dynamic array elements: " << t3res.mult << std::endl;
    }
    clear(t3res);

    std::cout << "Task4: Transpose matrix:" << std::endl;
    auto t4res = task4(fin, std::cout);
    std::cout << "Zero-value elements count: " << t4res.size << std::endl;
    std::cout << "Zero-value elements indices: ";
    for (size_t i = 0; i < t4res.size; i++)
        std::cout << "{" << t4res.indices[i * 2 + 0] << ", " << t4res.indices[i * 2 + 1] << "} ";
    std::cout << std::endl;
}