#include "flat.h"


FlatParams Flat::get_params() const {
    return flat_params;
}


string Flat::get_title() const {
    return flat_params.get_title();
}


int Flat::get_price() const {
    return flat_params.get_price();
}


int Flat::get_price_per_area() const {
    return flat_params.get_price_per_area();
}


string Flat::get_address() const {
    return flat_params.get_address();
}


string Flat::get_description() const {
    return flat_params.get_description();
}


string Flat::get_station() const {
    return flat_params.get_station();
}


string Flat::get_property() const {
    return flat_params.get_property();
}


int Flat::get_floor() const {
    return flat_params.get_floor();
}


int Flat::get_floor_max() const {
    return flat_params.get_floor_max();
}


string Flat::get_photo() const {
    return flat_params.get_photo();
}


void Flat::set_title(string &new_title)
{
    flat_params.set_title(new_title);
}


void Flat::set_price(int new_price) {
    flat_params.set_price(new_price);
}


void Flat::set_price_per_area(int new_price) {
    flat_params.set_price_per_area(new_price);
}


void Flat::set_address(string &new_address) {
    flat_params.set_address(new_address);
}


void Flat::set_description(string &new_description) {
    flat_params.set_description(new_description);
}


void Flat::set_station(string &new_station) {
    flat_params.set_station(new_station);
}


void Flat::set_property(string &new_property) {
    flat_params.set_property(new_property);
}


void Flat::set_floor(int new_floor) {
    flat_params.set_floor(new_floor);
}


void Flat::set_floor_max(int new_floor) {
    flat_params.set_floor_max(new_floor);
}


void Flat::set_photo(string &new_photo) {
    flat_params.set_photo(new_photo);
}
