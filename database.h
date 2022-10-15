#pragma once
#include "date.h"
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string_view>
#include <algorithm>

class Entry
{
private:
	Date date;
	std::string event;

public:
	Entry(Date d, std::string e)
		: date(std::move(d)), event(std::move(e))
	{}

	Date getDate() const { return date; }
	std::string_view getEvent() const { return event; }
};

std::ostream& operator<<(std::ostream& out, const Entry& aEntry);


class Database
{
public:
	bool Add(const Date& aDate, const std::string &aEvent);
	void Print(std::ostream& out) const;
	Entry Last(const Date& date) const;

	template <typename Predicat>
	int16_t RemoveIf(Predicat predicat);

	template <typename Predicat>
	std::vector<Entry> FindIf(Predicat predicat) const;

private:
	class EventsList
	{
	public:
		bool add(std::string aEvent);
		bool isEmpty() const;

		friend class Database;

	private:
		std::set<std::string> eventSet;
		std::vector<std::string_view> eventVec;
	};

	std::map<Date, EventsList> db;
};


template<typename Predicat>
int16_t Database::RemoveIf(Predicat predicat)
{
	int16_t counter{ 0 };
	std::vector<Date> datesToErase;

	for (auto& [date, eventList] : db) {
		auto it = std::stable_partition(eventList.eventVec.begin(), eventList.eventVec.end(), [&](const auto& event)
			{
				return !predicat(date, static_cast<std::string>(event));
			});
		for (auto i = it; i != eventList.eventVec.end(); i++)
		{
			eventList.eventSet.erase(static_cast<std::string>(*it));
			++counter;
		}
		eventList.eventVec.erase(it, eventList.eventVec.end());

		if (eventList.isEmpty()) datesToErase.push_back(date);
	}

	for (const auto& date : datesToErase) {
		db.erase(date);
	}

	return counter;
}

template<typename Predicat>
std::vector<Entry> Database::FindIf(Predicat predicat) const
{
	std::vector<Entry> result;
	for (const auto& [date, eventList] : db) {
		for (const auto& event : eventList.eventSet) {
			if (predicat(date, event))
				result.emplace_back(date, event);
		}
	}

	return result;
}


