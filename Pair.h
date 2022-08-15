#ifndef TEST13_1_PAIR_H
#define TEST13_1_PAIR_H

#include <utility>

template<class F, class S>
class Pair {
private:
    F m_first;
    S m_second;

public:
     Pair(F aFirst, S aSecond)
        : m_first(std::move(aFirst)), m_second(std::move(aSecond))
    {}

    F& first()  { return m_first; }
    const F& first() const { return m_first; }
    S& second() { return  m_second; }
    const S& second() const { return  m_second; }
};


#endif //TEST13_1_PAIR_H
