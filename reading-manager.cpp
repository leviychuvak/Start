#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <memory>
#include <deque>
#include <cassert>

//using namespace std;  лучше так не делать, чтобы не было конфликтов имен

class ReadingManager {
private:
	static constexpr size_t MAX_USERS_COUNT = 100'000 + 1;
	static constexpr size_t MAX_PAGES_COUNT = 1000 + 1;

public:
	enum class query_type
	{
		READ,
		CHEER
	};

	static query_type getQueryType() {
		while (true)
		{
			std::string type;
			std::cin >> type;
			std::cin.ignore(32767, '\n');
			if (type == "READ") return query_type::READ;
			if (type == "CHEER") return query_type::CHEER;
			std::cout << "Oops, that input is invalid.  Please try again." << std::endl;
		}
	}

	// Магические числа, лучше вынести в константы
	ReadingManager()
		: users_(MAX_USERS_COUNT, 0),
		arr(MAX_PAGES_COUNT, 0)
	{}

	//Названия методов с маленькой буквы
	void read(int user_id, int page_count) {
		//Нужна проверка на коректность параметров 
		assert(page_count < MAX_PAGES_COUNT && "Too many pages in Read()");
		assert(user_id < MAX_USERS_COUNT && "There isn't user with such index");

		if (users_[user_id] != 0) {
			int old_pages = users_[user_id];	
			for (int i = old_pages + 1; i <= page_count; ++i) {
				arr[i]++;
			}
			//Можно заменить на std::for_each
			/*auto itBegin = arr.begin() + old_pages + 1;
			auto itEnd = itBegin + page_count + 1;
			std::for_each(itBegin, itEnd, [](int& a) {a++; });*/
		}
		else {
			users_id.push_back(user_id);
			for (int i = 0; i <= page_count; ++i) {
				arr[i]++;
			}
		}

		users_[user_id] = page_count;
	}

	//Метод ничего не меняет, нужно сделать конст 
	double cheer(int user_id) const {
		assert(user_id < MAX_USERS_COUNT && "There isn't user with such index");

		int user_count = users_id.size();
		if (!users_[user_id]) return 0;
		if (user_count == 1) return 1;
		return (user_count - arr[users_[user_id]]) * 1.0 / (user_count - 1);
	}

//Поля нужно приватными делать
private:
	std::deque<int> users_; // <id -> pages_count>		
	//users_id используется только для получения количества пользователей которые читают книгу, если не нужно хранить их id, лучше заменить на счетчик
	std::vector<int> users_id; // <set<id>> 
	std::vector<int> arr;		//page-> number of users which read this page
};

int getInt() {
	while (true)
	{
		int t;
		std::cin >> t;
		if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "Oops, that input is invalid.  Please try again."<<std::endl;
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем лишние значения

			return t;
		}
	}
	
}

int main() {
	/*Для ускорения чтения данных отключается синхронизация
	cin и cout с stdio,
	а также выполняется отвязка cin от cout*/
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);


	//ReadingManager* manager = new ReadingManager(); 
	//Во первых выделили и не освободили
	//Во вторых нужно юзать RAII, в этом случае лучше unique_ptr

	std::unique_ptr<ReadingManager> manager = std::make_unique<ReadingManager>();

	//Часто используем ввод числа, можно вынести в отдельную функцию, которая будет валидировать ввод
	int query_count = getInt();

	for (int query_id = 0; query_id < query_count; ++query_id) {
		//query_type звучит как будто из него стоит сделать перечисление
		ReadingManager::query_type query_type = ReadingManager::getQueryType();
		int user_id = getInt();

		if (query_type == ReadingManager::query_type::READ) {
			int page_count = getInt();
			manager->read(user_id, page_count);
		}
		else if (query_type == ReadingManager::query_type::CHEER) {
			//лучше всегда использовать std::endl, т.к. он очищает буфер за собой
			std::cout << std::setprecision(6) << manager->cheer(user_id) << std::endl;
		}
	}

	return 0;
}

