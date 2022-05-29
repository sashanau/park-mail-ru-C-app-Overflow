#ifndef __FLAT_H__
#define __FLAT_H__


#include <iostream>
#include <string>
#include "flat_params.h"


using std::string;


class Flat
{
public:
    explicit Flat(FlatParams &flat_params): flat_params(flat_params) {};
    ~Flat() = default;

    [[nodiscard]] FlatParams get_params() const;

    [[nodiscard]] string get_title() const;
    [[nodiscard]] int get_price() const;
    [[nodiscard]] int get_price_per_area() const;
    [[nodiscard]] string get_address() const;
    [[nodiscard]] string get_description() const;
    [[nodiscard]] string get_station() const;
    [[nodiscard]] string get_property() const;
    [[nodiscard]] int get_floor() const;
    [[nodiscard]] int get_floor_max() const;
    [[nodiscard]] string get_photo() const;

    void set_title(string &new_title);
    void set_price(int new_price);
    void set_price_per_area(int new_price);
    void set_address(string &new_address);
    void set_description(string &new_description);
    void set_station(string &new_station);
    void set_property(string &new_property);
    void set_floor(int new_floor);
    void set_floor_max(int new_floor);
    void set_photo(string &new_photo);

private:
    FlatParams flat_params;
};


#endif  // __FLAT_H__