#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <map>

class Person {
public:
	void ChangeFirstName(int year, const std::string first_name);
	void ChangeLastName(int year, const std::string last_name);
	std::string GetFullName(int year) const;
private:
	std::map<int, std::string> firstNames;
	std::map<int, std::string> lastNames;
};

#endif // !PERSON_H





