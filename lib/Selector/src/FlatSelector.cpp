#include "FlatSelector.h"
#include "TravelTimeGetter.h"
#include "SelectorException.h"

#include <memory>

FlatSelector::FlatSelector(std::unique_ptr<SQLiteDataBase>& data_base_) : db(std::move(data_base_)) {
    if(!db){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "FlatSelector::FlatSelector - std::unique_ptr<IDataBase> data_base_ is nullptr\n");
        return;
    }
}


std::vector<std::string> FlatSelector::get_addr_vect(const std::vector<Flat>& flats){
    std::vector<std::string> result;

    for(const Flat &sel_flat : flats){
        result.push_back(sel_flat.get_address());
    }

    return result;
}


std::vector<int> FlatSelector::get_travel_time(const std::vector<std::string>& origins, const std::string& dest){
    std::vector<int> result;
    
	TravelTimeGetter calc_time;
	result = calc_time.make_request(origins, dest);

    return result;
}


std::vector<FlatAndTravelTime> FlatSelector::get_by_travel_time(const int count, const std::string& dest){
    std::vector<FlatAndTravelTime> result;

    std::vector<Flat> origins = db->get_random_flats(count);
    
    if(origins.empty()){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "FlatSelector::get_by_travel_time - db->get_random_flats empty\n");
        return {};
    }

    std::vector<std::string> origins_addr = get_addr_vect(origins);
    std::vector<int> travel_time = get_travel_time(origins_addr, dest);

    if(travel_time.empty()){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "FlatSelector::get_by_travel_time - travel_time empty\n");
        return {};
    }

    int length = origins_addr.size();
    for(int i = 0; i < length; i++){
        result.push_back(FlatAndTravelTime(origins[i], travel_time[i]));
    }
    return result;
}
