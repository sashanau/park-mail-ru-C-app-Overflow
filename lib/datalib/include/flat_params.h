#ifndef __FLAT_PARAMS_H__
#define __FLAT_PARAMS_H__


#include <iostream>
#include <string>


using std::string;

class FlatParams {
public:
    FlatParams(const string &title, int price, int price_per_area=0,
               const string &address="", const string &description="",
               const string &station="", const string &property="", int floor=0,
               int floor_max=0, const string &photo="");
    ~FlatParams() = default;

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
    string title;
    int price;
    int price_per_area;
    string address;
    string description;
    string station;
    std::string property;
    int floor;
    int floor_max;
    string photo;
};


#endif  // __FLAT_PARAMS_H__
