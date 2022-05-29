#ifndef _FLATANDTRAVELTIME_H__
#define _FLATANDTRAVELTIME_H__

#include "Selector.h"

#include <memory>

class FlatAndTravelTime{
public:
    FlatAndTravelTime(Flat a_flat, int a_time) : 
        flat(a_flat),
        travel_time(a_time)
    {
    }

    int get_travel_time() const { return travel_time; }
    Flat get_flat() const { return flat; }
private:
    Flat flat;
    int travel_time;
};

#endif
