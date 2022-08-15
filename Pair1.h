#ifndef TEST13_1_PAIR1_H
#define TEST13_1_PAIR1_H

template<class T>
class Pair1 {
private:
    T m_first;
    T m_second;

public:
    Pair1(const T &aFirst, const T &aSecond)
        : m_first(aFirst), m_second(aSecond)
    {}

    T& first() { return  m_first; }
    const T& first() const { return m_first; }
    T& second() { return m_second; }
    const T& second() const { return m_second; }

public:

};


#endif //TEST13_1_PAIR1_H
