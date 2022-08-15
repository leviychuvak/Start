#ifndef TEST13_1_STRINGVALUEPAIR_H
#define TEST13_1_STRINGVALUEPAIR_H

#include <string>
#include "Pair.h"

template<class T>
class StringValuePair: public Pair<std::string, T> {
public:
    explicit StringValuePair(const std::string &aString, const T &aValue)
        : Pair<std::string, T>(aString, aValue)
    {}

};


#endif //TEST13_1_STRINGVALUEPAIR_H
