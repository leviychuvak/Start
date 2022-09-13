#include <iostream>
#include <map>
#include <optional>

template <typename T1, typename T2>
T2& GetRefStrict(std::map<T1, T2>& m, const T1& key) {
    try{
        T2& t = m.at(key);
        return t;
    }catch (std::out_of_range &e) {}
    throw std::runtime_error("Map does not contain this key");
    // или лучше пробросить out_of_range дальше в caller?
}

int main()
{
    std::map<int, std::string> m = { {0, "value"} };
    try{
        std::string& item = GetRefStrict(m, 1);
        item = "newvalue";
    }
    catch (const std::runtime_error& e){
        std::cerr << e.what();
    }
    
    std::cout << m[0] << std::endl; // выведет newvalue

    return 0;
}