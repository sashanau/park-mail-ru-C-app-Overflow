#include <gtest/gtest.h>

extern "C"
{
    #include "flat.h"
}


TEST(FLAT_TEST, GET_PRICE)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    EXPECT_EQ(price, flat.get_price());   
}


TEST(FLAT_TEST, GET_CITY)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    EXPECT_EQ(city, flat.get_city());   
}


TEST(FLAT_TEST, GET_ADDRESS)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    EXPECT_EQ(address, flat.get_address());   
}


TEST(FLAT_TEST, GET_ROOMS)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    EXPECT_EQ(rooms, flat.get_rooms());   
}


TEST(FLAT_TEST, GET_SQUARE)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    EXPECT_EQ(square, flat.get_square());   
}


TEST(FLAT_TEST, GET_PHOTO_URLS)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    std::vector<std::string> getting_urls = flat.get_photo_urls());   
    
    EXPECT_EQ(photo_urls.size(), getting_urls.size());
    for (int i = 0; i < photo_urls.size(); i++)
        EXPECT_EQ(photo_urls[i], getting_urls[i]);
}


TEST(FLAT_TEST, GET_NEAREST_METRO)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    std::vector<std::string> getting_metro = flat.get_nearest_metro());   
    
    EXPECT_EQ(nearest_metro.size(), getting_metro.size());
    for (auto& [key, value]: getting_metro)
        EXPECT_EQ(nearest_metro[key], getting_metro[key]);
}


TEST(FLAT_TEST, GET_LIKES)
{    
    int price = 1000;
    std::string city = "Moscow";
    std::string address = "BMSTU, VK education";
    int rooms = 10;
    int square = 900;
    int floor = 3;
    std::vector<std::string> photo_urls = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes = { 1, 2, 3 };
    
    Flat flat(price, city, address, rooms, square, floor, photo_urls, nearest_metro, likes);
    
    std::vector<std::string> getting_likes = flat.get_likes());   
    
    EXPECT_EQ(likes.size(), getting_likes.size());
    for (int i = 0; i < likes.size(); i++)
        EXPECT_EQ(likes[i], getting_likes[i]);
}