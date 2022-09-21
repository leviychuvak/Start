#include "Person.h"

void Person::ChangeFirstName(int year, const std::string& first_name)
{
	firstNames[year] = first_name;
}

void Person::ChangeLastName(int year, const std::string& last_name)
{
	lastNames[year] = last_name;
}

std::string Person::GetFullName(int year) const
{
	bool fn = true;
	bool ln = true;
	auto fnIter = firstNames.upper_bound(year);
	auto lnIter = lastNames.upper_bound(year);
	std::string res{};

	if (firstNames.empty() || fnIter == firstNames.begin())
		fn = false;
	if (lastNames.empty() || lnIter == lastNames.begin())
		ln = false;

	if (fn && ln)
		return (--fnIter)->second + " " + (--lnIter)->second;
	if (fn && !ln)
		return (--fnIter)->second + " with unknown last name";
	if (!fn && ln)
		return (--lnIter)->second + " with unknown first name";

	return "Incognito";
}
