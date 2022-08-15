#ifndef TEST13_1_PAIR_H
#define TEST13_1_PAIR_H

template<class F, class S>
class Pair {
private:
    F m_first;
    S m_second;

public:
    explicit Pair(const F &aFirst, const S &aSecond)
        : m_first(aFirst), m_second(aSecond)
    {}

    F& first()  { return m_first; }
    const F& first() const { return m_first; }
    S& second() { return  m_second; }
    const S& second() const { return  m_second; }
};


#endif //TEST13_1_PAIR_H
