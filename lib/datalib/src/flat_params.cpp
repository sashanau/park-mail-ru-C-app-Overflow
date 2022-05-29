#include "flat_params.h"


FlatParams::FlatParams(const string &title, const int price, const int price_per_area, const string &address,
                       const string &description, const string &station, const string &property, const int floor,
                       const int floor_max, const string &photo) {
    this->title = title;
    this->price = price;
    this->price_per_area = price_per_area;
    this->address = address;
    this->description = description;
    this->station = station;
    this->property = property;
    this->floor = floor;
    this->floor_max = floor_max;
    this->photo = photo;
}


string FlatParams::get_title() const {
    return title;
}


int FlatParams::get_price() const {
    return price;
}


int FlatParams::get_price_per_area() const {
    return price_per_area;
}


string FlatParams::get_address() const {
    return address;
}


string FlatParams::get_description() const {
    return description;
}


string FlatParams::get_station() const {
    return station;
}


string FlatParams::get_property() const {
    return property;
}


int FlatParams::get_floor() const {
    return floor;
}


int FlatParams::get_floor_max() const {
    return floor_max;
}


string FlatParams::get_photo() const {
    return photo;
}


void FlatParams::set_title(string &new_title)
{
    title = new_title;
}


void FlatParams::set_price(int new_price) {
    price = new_price;
}


void FlatParams::set_price_per_area(int new_price) {
    price_per_area = new_price;
}


void FlatParams::set_address(string &new_address) {
    address = new_address;
}


void FlatParams::set_description(string &new_description) {
    description = new_description;
}


void FlatParams::set_station(string &new_station) {
    station = new_station;
}


void FlatParams::set_property(string &new_property) {
    property = new_property;
}


void FlatParams::set_floor(int new_floor) {
    floor = new_floor;
}


void FlatParams::set_floor_max(int new_floor) {
    floor_max = new_floor;
}


void FlatParams::set_photo(string &new_photo) {
    photo = new_photo;
}
