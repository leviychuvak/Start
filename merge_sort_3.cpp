#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	// Напишите реализацию функции,
	// не копируя сортируемые элементы
	if (range_end - range_begin < 2) return;

	vector<typename RandomIt::value_type> elements(
		std::make_move_iterator(range_begin), 
		std::make_move_iterator(range_end));

	auto third = std::distance(elements.begin(), elements.end()) / 3;

	MergeSort(elements.begin(), elements.begin() + third);
	MergeSort(elements.begin() + third, elements.begin() + 2 * third);
	MergeSort(elements.begin() + 2 * third, elements.end());

	vector<typename RandomIt::value_type> temp;
	
	std::merge(
		elements.begin(), elements.begin() + third,
		elements.begin() + third, elements.begin() + 2 * third,
		std::back_inserter(temp));
	std::merge(
		temp.begin(), temp.end(),
		elements.begin() + 2 * third, elements.end(),
		range_begin
	);
}

void TestIntVector() {
	vector<int> numbers = { 6, 1, 3, 9, 1, 9, 8, 12, 1 };
	MergeSort(begin(numbers), end(numbers));
	ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestIntVector);
	return 0;
}
