#ifndef TEST13_1_PAIR1_H
#define TEST13_1_PAIR1_H

#include <utility>

template<class T>
class Pair1 {
private:
    T m_first;
    T m_second;

public:
     Pair1(T aFirst,  T aSecond)
        : m_first(std::move(aFirst)), m_second(std::move(aSecond))
    {}

    T& first() { return  m_first; }
    const T& first() const { return m_first; }
    T& second() { return m_second; }
    const T& second() const { return m_second; }

public:

};


#endif //TEST13_1_PAIR1_H
