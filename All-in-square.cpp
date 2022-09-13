#include <iostream>
#include <vector>
#include <map>
#include <utility>

template <typename T> auto Sqr(T &&arg);
template <typename T1, typename T2> std::pair<T1, T2> Sqr(std::pair<T1, T2> p);
template <typename T1, typename T2> std::map<T1, T2> Sqr(std::map<T1, T2> m);
template <typename T1, typename T2> std::map<T1, T2> Sqr(std::map<T1, T2> m);

template <typename T>
auto Sqr(T &&arg) {
    return arg * arg;
}

template <typename T1, typename T2>
std::pair<T1, T2> Sqr(std::pair<T1, T2> p) {
    return std::make_pair(Sqr(p.first), Sqr(p.second));
}

template <typename T>
std::vector<T> Sqr(std::vector<T> v) {
    std::vector<T> res;
    for (auto& el : v) res.push_back(Sqr(el));
    return res;
}

template <typename T1, typename T2>
std::map<T1, T2> Sqr(std::map<T1, T2> m) {
    std::map<T1, T2> res;
    for (auto& [k, v] : m) res.emplace(k, Sqr(v));
    return res;
}

int main()
{
    // Пример вызова функции
    std::vector<int> v = { 1, 2, 3 };
    std::cout << "vector:";
    for (int x : Sqr(v)) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;
    std::map<int, std::pair<int, int>> map_of_pairs = {
     {4, {2, 2}},
     {7, {4, 3}}
    };
    std::cout << "map of pairs:" << std::endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
    }

    return 0;
}
