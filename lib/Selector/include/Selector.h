#ifndef __SELECTOR_H__
#define __SELECTOR_H__

#include <vector>
#include "sqlite_database.h"
#include "FlatAndTravelTime.h"

class ISelector{
public:
    virtual std::vector<FlatAndTravelTime> get_by_travel_time(const int count, const std::string& dest) = 0;
    virtual ~ISelector() = default;
};

#endif
