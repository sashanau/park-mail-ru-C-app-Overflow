#ifndef __FLATSELECTOR_H__
#define __FLATSELECTOR_H__

#include "Selector.h"

class FlatSelector: public ISelector{
public: 
    FlatSelector(std::unique_ptr<SQLiteDataBase>& data_base_);
    ~FlatSelector() override {};
    std::vector<FlatAndTravelTime> get_by_travel_time(const int count, const std::string& dest) override;
private:
    std::vector<std::string> get_addr_vect(const std::vector<Flat>& flats);
    std::vector<int> get_travel_time(const std::vector<std::string>& origins, const std::string& dest);
    std::unique_ptr<SQLiteDataBase> db;
};

#endif
