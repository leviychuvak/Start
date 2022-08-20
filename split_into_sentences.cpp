﻿#include "test_runner.h"

#include <vector>
#include <algorithm>

using namespace std;

// Объявляем Sentence<Token> для произвольного типа Token
// синонимом vector<Token>.
// Благодаря этому в качестве возвращаемого значения
// функции можно указать не малопонятный вектор векторов,
// а вектор предложений — vector<Sentence<Token>>.
template <typename Token>
using Sentence = vector<Token>;

template <typename TokenIter>
TokenIter findEndOfSentence(TokenIter begin, TokenIter end) {
    TokenIter endOfSentenceIter = std::adjacent_find(begin, end, [](const auto& left, const auto& right)
        {return left.IsEndSentencePunctuation() && !right.IsEndSentencePunctuation(); });

    return endOfSentenceIter == end ? end : next(endOfSentenceIter);
}

// Класс Token имеет метод bool IsEndSentencePunctuation() const
template <typename Token>
vector<Sentence<Token>> SplitIntoSentences(vector<Token> tokens) {
    // Напишите реализацию функции, не копируя объекты типа Token

    std::vector<Sentence<Token>> resultSentences;
    auto tBegin = begin(tokens);

    while (tBegin != tokens.end())
    {
        auto sentenceEnd = findEndOfSentence(tBegin, tokens.end());
        resultSentences.push_back(Sentence<Token>(
            std::make_move_iterator(tBegin),
            std::make_move_iterator(sentenceEnd)
            ));
        tBegin = sentenceEnd;
    }

    return resultSentences;
}


struct TestToken {
    string data;
    bool is_end_sentence_punctuation = false;

    bool IsEndSentencePunctuation() const {
        return is_end_sentence_punctuation;
    }
    bool operator==(const TestToken& other) const {
        return data == other.data && is_end_sentence_punctuation == other.is_end_sentence_punctuation;
    }
};

ostream& operator<<(ostream& stream, const TestToken& token) {
    return stream << token.data;
}

// Тест содержит копирования объектов класса TestToken.
// Для проверки отсутствия копирований в функции SplitIntoSentences
// необходимо написать отдельный тест.
void TestSplitting() {
    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({ {"Split"}, {"into"}, {"sentences"}, {"!"} })),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!"}}
            })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({ {"Split"}, {"into"}, {"sentences"}, {"!", true} })),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!", true}}
            })
    );

    ASSERT_EQUAL(
        SplitIntoSentences(vector<TestToken>({ {"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}, {"Without"}, {"copies"}, {".", true} })),
        vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!", true}, {"!", true}},
            {{"Without"}, {"copies"}, {".", true}},
            })
            );
}

struct NoncopyableTokens {
    TestToken value;

    NoncopyableTokens(const NoncopyableTokens&) = delete;
    NoncopyableTokens& operator=(const NoncopyableTokens&) = delete;

    NoncopyableTokens(NoncopyableTokens&&) = default;
    NoncopyableTokens& operator=(NoncopyableTokens&&) = default;
};

bool operator == (const NoncopyableTokens& lhs, const NoncopyableTokens& rhs) {
    return lhs.value == rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableTokens& v) {
    return os << v.value;
}

void TestAvoidsCopying() {

    vector<TestToken> v;
    v.push_back({ "Split" });
    v.push_back({ "into" });
    v.push_back({ "sentences" });
    v.push_back({ "!", true });

    vector<Sentence<TestToken>> expected = SplitIntoSentences(v);

    ASSERT_EQUAL(expected, vector<Sentence<TestToken>>({
            {{"Split"}, {"into"}, {"sentences"}, {"!", true} }
        }));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSplitting);
    RUN_TEST(tr, TestAvoidsCopying);
    return 0;
}
