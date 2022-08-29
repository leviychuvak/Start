#include <iostream>
#include <string>
#include <array>
#include <algorithm>

struct Student
{
    std::string name{};
    int mark{};
};

void task1() {
    std::array<Student, 8> arr{
        Student{.name = "Albert", .mark = 3 },
        Student{.name = "Ben", .mark = 5 },
        Student{.name = "Christine", .mark = 2 },
        Student{.name = "Dan", .mark = 8 },
        Student{.name = "Enchilada", .mark = 4 },
        Student{.name = "Francis", .mark = 1 },
        Student{.name = "Greg", .mark = 3 },
        Student{.name = "Hagrid", .mark = 5 },
    };

    auto best{ std::max_element(arr.begin(), arr.end(), [](const auto &lhs, const auto &rhs)
        {
            return lhs.mark < rhs.mark;
        })
    };

    std::cout << best->name << " is the best student\n";
}