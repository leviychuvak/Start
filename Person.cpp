#include "Person.h"

void Person::ChangeFirstName(int year, std::string first_name)
{
	firstNames.insert({ year, std::move(first_name) });
}

void Person::ChangeLastName(int year,  std::string last_name)
{
	lastNames.insert({ year, std::move(last_name) });
}

std::string Person::GetFullName(int year) const
{
	bool firstnameExist = true;
	bool lastnameExist = true;
	auto nextFirstnameIter = firstNames.upper_bound(year);
	auto nextLastnameIter = lastNames.upper_bound(year);
	std::string res{};

	firstnameExist = !firstNames.empty() && nextFirstnameIter != firstNames.begin();
	lastnameExist = !lastNames.empty() && nextLastnameIter != lastNames.begin();

	if (firstnameExist && lastnameExist)
		return (--nextFirstnameIter)->second + " " + (--nextLastnameIter)->second;
	if (firstnameExist && !lastnameExist)
		return (--nextFirstnameIter)->second + " with unknown last name";
	if (!firstnameExist && lastnameExist)
		return (--nextLastnameIter)->second + " with unknown first name";

	return "Incognito";
}
