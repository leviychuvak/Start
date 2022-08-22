#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	// Напишите реализацию функции,
	// не копируя сортируемые элементы
	if (distance(range_begin, range_end) < 2) return;

	vector<typename RandomIt::value_type> tRange;
	std::move(range_begin, range_end, std::back_inserter(tRange));

	auto third = distance(range_begin, range_end) / 3;

	MergeSort(begin(tRange), begin(tRange) + third);
	MergeSort(begin(tRange) + third, begin(tRange) + third * 2);
	MergeSort(begin(tRange) + third * 2, end(tRange));

	vector<typename RandomIt::value_type> tMerge;

	std::merge(
		std::make_move_iterator(begin(tRange)), std::make_move_iterator(begin(tRange) + third),
		std::make_move_iterator(begin(tRange) + third), std::make_move_iterator(begin(tRange) + third * 2),
		std::back_inserter(tMerge));

	std::merge(
		std::make_move_iterator(begin(tMerge)), std::make_move_iterator(end(tMerge)),
		std::make_move_iterator(begin(tRange) + third * 2), std::make_move_iterator(end(tRange)),
		range_begin);
}

struct NoncopyableInt {
	int value;

	NoncopyableInt(int aValue): value(aValue) {}

	NoncopyableInt(const NoncopyableInt&) = delete;
	NoncopyableInt& operator=(const NoncopyableInt&) = delete;

	NoncopyableInt(NoncopyableInt&&) = default;
	NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
	return lhs.value == rhs.value;
}

bool operator < (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
	return lhs.value < rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
	return os << v.value;
}


void TestIntVector() {
	vector<int> numbers = { 6, 1, 3, 9, 1, 9, 8, 12, 1 };
	MergeSort(begin(numbers), end(numbers));
	ASSERT(is_sorted(begin(numbers), end(numbers)));
}

void TestNoncopyableIntVector() {
	vector< NoncopyableInt> numbers;
	numbers.push_back(6);
	numbers.push_back(1);
	numbers.push_back(3);
	numbers.push_back(9);
	numbers.push_back(1);
	numbers.push_back(9);
	numbers.push_back(8);
	numbers.push_back(12);
	numbers.push_back(1);

	MergeSort(begin(numbers), end(numbers));
	ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestIntVector);
	RUN_TEST(tr, TestNoncopyableIntVector);
	return 0;
}
