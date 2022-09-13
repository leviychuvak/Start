#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    std::string bus;
    std::string stop;
    std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
    std::string inputOperationType;
    is >> inputOperationType;

    if (inputOperationType == "NEW_BUS") {
        q.type = QueryType::NewBus;
        is >> q.bus;
        int busCount{};
        is >> busCount;
        q.stops.clear();
        q.stops.reserve(busCount);
        for (size_t i = 0; i < busCount; ++i){
            std::string stop{};
            is >> stop;
            q.stops.push_back(std::move(stop));
        }
        return is;
    }
    if (inputOperationType == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
        return is;
    }
    if (inputOperationType == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
        return is;
    }
    if (inputOperationType == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
        return is;
    }

    throw std::logic_error("Something went wrong, unknown QueryType in right argument of operator '>>'");
}

struct BusesForStopResponse {
    std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
    if (r.buses.empty()) 
        return os << "No stop"<<std::endl;
    os << "{";
    for (const auto& bus : r.buses) {
        os << bus << " ";
    }
    
    os <<"}" << std::endl;
    return os;
}

struct StopsForBusResponse {
    std::vector<std::string> stops;
    std::vector<std::vector<std::string>> buses;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
    if (r.stops.empty()) {
        return os << "No bus" << std::endl;
    }

    for (size_t i = 0; i < r.stops.size(); ++i)
    {
        os << "Stop " << r.stops[i] << ": {";
        for (const auto& bus : r.buses[i])
            os << bus << " ";
        os <<"}" << std::endl;
    }
    return os;
}

struct AllBusesResponse {
    std::map<std::string, std::vector<std::string>> buses;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
    if (r.buses.empty()) {
        os << "No bus" << std::endl;
        return os;
    }

    for (const auto& bus : r.buses) {
        os << "Buss " << bus.first << ": {";
        for (const auto& stop : bus.second) {
            os << stop << " ";
        }
        os << "}" << std::endl;
    }
    return os;
}

class BusManager {
public:
    void AddBus(const std::string& bus, std::vector<std::string>&& stops) {
        std::ranges::move(stops, std::back_inserter(buses_to_stops[bus]));
        for (const auto& stop : buses_to_stops[bus]) {
            stops_to_buses[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const std::string& stop) const {
        BusesForStopResponse res;
        if (!stops_to_buses.contains(stop)) return res;
        for (const auto& bus : stops_to_buses.at(stop)) {
            res.buses.push_back(bus);
        }
        return res;
    }

    StopsForBusResponse GetStopsForBus(const std::string& bus) const {
        StopsForBusResponse res;
        if (!buses_to_stops.contains(bus)) return res;
        for (const auto& stop : buses_to_stops.at(bus)) {
            res.stops.push_back(stop);
            if (stops_to_buses.at(stop).size() == 1) {
                res.buses.push_back({ "no interchange" });
            }
            else{
                std::vector<std::string> temp;
                copy_if(stops_to_buses.at(stop).begin(), stops_to_buses.at(stop).end(), std::back_inserter(temp),
                    [&bus](const auto& str) {return str != bus; });
                res.buses.push_back(std::move(temp));
            }
        }
        return res;
    }

    AllBusesResponse GetAllBuses() const {
        AllBusesResponse res;
        if (buses_to_stops.empty()) return res;
        for (const auto& bus : buses_to_stops) {
            res.buses[bus.first] = bus.second;
        }
        return res;
    }
private:
    std::unordered_map<std::string, std::vector<std::string>> stops_to_buses;
    std::unordered_map<std::string, std::vector<std::string>> buses_to_stops;
};

int main() {
    int query_count;
    Query q;

    std::cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        try
        {
            std::cin >> q;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            --i;
            continue;
        }
        switch (q.type) {
        case QueryType::NewBus:
            bm.AddBus(std::move(q.bus), std::move(q.stops));
            break;
        case QueryType::BusesForStop:
            std::cout << bm.GetBusesForStop(q.stop) << std::endl;
            break;
        case QueryType::StopsForBus:
            std::cout << bm.GetStopsForBus(q.bus) << std::endl;
            break;
        case QueryType::AllBuses:
            std::cout << bm.GetAllBuses() << std::endl;
            break;
        }
    }

    return 0;
}
