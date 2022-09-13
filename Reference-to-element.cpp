#include <iostream>
#include <map>

template <typename T1, typename T2>
T2& GetRefStrict(std::map<T1, T2>& m, const T1& key) {
    //if(m.count(key)) return m[key]; //before C++20
    
    if (m.contains(key)) return m[key]; //Since C++20

    else throw std::runtime_error("Map does not contain this key");
}

int main()
{
    std::map<int, std::string> m = { {0, "value"} };
    try{
        std::string& item = GetRefStrict(m, 0);
        item = "newvalue";
    }
    catch (const std::runtime_error& e){
        std::cerr << e.what();
    }
    
    std::cout << m[0] << std::endl; // выведет newvalue

    return 0;
}