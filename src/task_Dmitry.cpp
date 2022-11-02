#include <iostream>
#include <fstream>
#include <string>

#include "maxinmatrix.h"
#include "MinInArray.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"


#include "task8.h"

#include "input.h"
#include "testing.h"

enum class Task : int
{
    Exit,
    First,
    Second,
    Third,
    ThirdTest = 30,
    Fourth = 4,
    FourthTest = 40,
    Fifth = 5,
    FifthTest = 50,
    Sixth = 6,
    Seventh,
    Eighth
};

int main()
{
    std::ifstream fin("input.txt");
    std::istream& in = fin;

    std::ostream& out = std::cout;

    std::cout
        << static_cast<int>(Task::Exit) << ": Exit," << std::endl
        << static_cast<int>(Task::First) << ": Run task 1," << std::endl
        << static_cast<int>(Task::Second) << ": Run task 2," << std::endl
        << static_cast<int>(Task::Third) << ": Run task 3," << std::endl
        << static_cast<int>(Task::ThirdTest) << ": Run task 3 tests," << std::endl
        << static_cast<int>(Task::Fourth) << ": Run task 4," << std::endl
        << static_cast<int>(Task::FourthTest) << ": Run task 4 tests," << std::endl
        << static_cast<int>(Task::Fifth) << ": Run task 5," << std::endl
        << static_cast<int>(Task::FifthTest) << ": Run task 5 tests," << std::endl
        << static_cast<int>(Task::Sixth) << ": Run task 6," << std::endl
        << static_cast<int>(Task::Seventh) << ": Run task 7," << std::endl
        << static_cast<int>(Task::Eighth) << ": Run task 8" << std::endl
        << "Write youre choise: ";

    int task_number = std::numeric_limits<int>::max();
    for (;task_number;)
    {
        if (!read_number(std::cin, task_number))
            std::cout << "Incorrect input data" << std::endl;

        switch (static_cast<Task>(task_number))
        {
        case Task::Exit:
            break;
        case Task::First:
            break;
        case Task::Second:
            break;
        case Task::Third:
            break;
        case Task::Fourth:
            break;
        case Task::Fifth:
            break;
        case Task::Sixth:
            break;
        case Task::Seventh:
            break;
        case Task::Eighth:
            break;
        default:
            break;
        }
    }

    auto max = find_max_in_matrix(in, out);
    out << "Max element in matrix: " << max.value << std::endl;

    auto min = find_min_in_array(in, out);
    out << "Min element in array: " << min.value
        << ", index: " << min.index << std::endl;

    auto t3res = task3(in, out);
    if (t3res.array)
    {
        out << "Dynamic array as matrix parse result:" << std::endl;
        bool f = true;
        for (auto it = t3res.array;
            it != t3res.array + t3res.size;
            ++it)
            out << (f ? (f = false, "") : ", ") << *it;
        out << std::endl;
        out << "multiplication of dynamic array elements: " << t3res.mult << std::endl;
    }
    clear(t3res);

    out << "Task4: Transpose matrix:" << std::endl;
    auto t4res = task4(in, out);
    out << "Zero-value elements count: " << t4res.size << std::endl;
    out << "Zero-value elements indices: ";
    for (size_t i = 0; i < t4res.size; i++)
        out << "{" << t4res.indices[i * 2 + 0] << ", " << t4res.indices[i * 2 + 1] << "} ";
    out << std::endl;

    out << "Task5: array" << std::endl;
    auto t5res = task5(in, out);
    if (t5res.array)
    {
        out << "Array length: " << t5res.size << std::endl;
        bool f = true;
        for (auto it = t5res.array;
            it != t5res.array + t5res.size;
            it++)
            out << (f ? (f = false, "") : ", ") << *it;
        out << std::endl;
        out << "Arithmetic mean: " << t5res.arithm_mean << std::endl;
    }

    auto t8res = task8(in, out);
    if (t8res != std::numeric_limits<int64_t>::min())
        out << t8res << std::endl;
}