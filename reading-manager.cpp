#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <memory>
#include <any>
#include <optional>
#include <deque>

using namespace std;

class ReadingManager {
public:
	ReadingManager()
		:  users_(100'000 + 1, 0),
			arr(1001, 0)
	{}

	void Read(int user_id, int page_count) {
		if (users_[user_id] != 0) {
			int old_pages = users_[user_id];
			for (int i = old_pages + 1; i <= page_count; ++i) {
				arr[i]++;
			}
		}
		else {
			users_id.push_back(user_id);
			for (int i = 0; i <= page_count; ++i) {
				arr[i]++;
			}
		}

		users_[user_id] = page_count;
	}

	double Cheer(int user_id) {
		int user_count = users_id.size();
		if (!users_[user_id]) return 0;
		if (user_count == 1) return 1;
		return (user_count - arr[users_[user_id]]) * 1.0 / (user_count - 1);
	}

	deque<int> users_; // <id -> pages_count>
	vector<int> users_id; // <set<id>>
	vector<int> arr;
};

int main() {
	 /*Для ускорения чтения данных отключается синхронизация
	 cin и cout с stdio,
	 а также выполняется отвязка cin от cout*/
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ReadingManager* manager = new ReadingManager();

	int query_count;
	cin >> query_count;

	for (int query_id = 0; query_id < query_count; ++query_id) {
		string query_type;
		cin >> query_type;
		int user_id;
		cin >> user_id;

		if (query_type == "READ") {
			int page_count;
			cin >> page_count;
			manager->Read(user_id, page_count);
		}
		else if (query_type == "CHEER") {
			cout << setprecision(6) << manager->Cheer(user_id) << "\n";
		}
	}

	return 0;
}

