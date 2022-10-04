#include "database.h"
#include <stdexcept>

std::ostream& operator<<(std::ostream& out, const Entry& aEntry)
{
    out << aEntry.getDate() << " " << aEntry.getEvent();
    return out;
}

bool Database::EventsList::add(std::string aEvent)
{
    auto [iter, flag] = eventSet.insert(aEvent);
    if (flag) {
        eventVec.push_back(*iter);
    }
    return flag;
}

bool Database::EventsList::isEmpty() const
{
    return eventVec.empty();
}


bool Database::Add(const Date& aDate, const std::string aEvent)
{
    return bd[aDate].add(aEvent);
}

void Database::Print(std::ostream& out) const
{
    for (const auto& [date, eventList] : bd) {
        for (const auto& event : eventList.eventVec)
            out << date << " " << event << std::endl;
    }
}

Entry Database::Last(const Date& date) const
{
    if (bd.empty()){
        throw std::invalid_argument("");
    }
     auto nextAfterDesiredIter = bd.upper_bound(date);
    if (nextAfterDesiredIter != bd.begin()) {
        const auto& [date, events] = *(--nextAfterDesiredIter);
        std::string lastInDate = static_cast<std::string>(*events.eventVec.rbegin());
        return { date, lastInDate };
    }

    throw std::invalid_argument("");
}

