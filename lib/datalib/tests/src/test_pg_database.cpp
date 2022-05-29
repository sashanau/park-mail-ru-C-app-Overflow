#include <gtest/gtest.h>

extern "C"
{
    #include "pg_database.h"
}


TEST(DATABASE, CONNECT)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    PGDataBase db(params);
    
    EXPECT_TRUE(db.connect_db() == true);
}


TEST(DATABASE, ADD_USER)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    PGDataBase db(params);
    
    EXPECT_TRUE(db.connect_db() == true);
    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 2, 3 };
    
    User user(name, surname, address, age, city, likes);
    
    EXPECT_TRUE(db.add_user(user) == true);
    
    User getting_user = get_user(1);
     
    EXPECT_EQ(getting_user.get_full_name(), user.get_full_name());
    EXPECT_EQ(getting_user.get_address(), user.get_address());
    EXPECT_EQ(getting_user.get_age(), user.get_age());
    EXPECT_EQ(getting_user.get_city(), user.get_city());
    EXPECT_EQ(getting_user.get_likes(), user.get_likes());
}


TEST(DATABASE, ADD_USERS)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    PGDataBase db(params);
    
    EXPECT_TRUE(db.connect_db() == true);
    
    std::string name_1 = "Ilya";
    std::string surname_1 = "Klimov";
    std::string address_1 = "BMSTU, VK education";
    int age_1 = 20;
    std::string city_1 = "Moscow";
    std::vector<int> likes_1 = { 1, 2, 3 };
    User user_1(name_1, surname_1, address_1, age_1, city_1, likes_2);
    
    std::string name_2 = "Ivan";
    std::string surname_2 = "Ivanov";
    std::string address_2 = "BMSTU, not VK education";
    int age_2 = 30;
    std::string city_2 = "Moscow";
    std::vector<int> likes_2 = { 6, 2, 3 };
    User user_2(name_2, surname_2, address_2, age_2, city_2, likes_2);
    
    std::vector<User> users = { user_1, user_2 };
    
    EXPECT_TRUE(db.add_users(users) == true);
    
    std::vector<int> ids = { 1, 2 };
    std::vector<User> getting_users = get_users(ids);
    
    for (int i = 0; i < users.size(); i++)
    {
		EXPECT_EQ(getting_users[i].get_full_name(), users[i].get_full_name());
		EXPECT_EQ(getting_users[i].get_address(), users[i].get_address());
		EXPECT_EQ(getting_users[i].get_age(), users[i].get_age());
		EXPECT_EQ(getting_users[i].get_city(), users[i].get_city());
		EXPECT_EQ(getting_users[i].get_likes(), users[i].get_likes());
    }
}


TEST(DATABASE, ADD_FLAT)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    PGDataBase db(params);
    
    EXPECT_TRUE(db.connect_db() == true);
    
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
    
    EXPECT_TRUE(db.add_flat(flat) == true);
    
    Flat getting_flat = get_flat(1);
     
    EXPECT_EQ(getting_flat.get_price(), flat.get_price());
    EXPECT_EQ(getting_flat.get_city(), flat.get_city());
    EXPECT_EQ(getting_flat.get_address(), flat.get_address());
    EXPECT_EQ(getting_flat.get_rooms(), flat.get_rooms());
    EXPECT_EQ(getting_flat.get_square(), user.get_square());
    EXPECT_EQ(getting_flat.get_photo_urls(), user.get_photo_urls());
    EXPECT_EQ(getting_flat.get_nearest_metro(), user.get_nearest_metro());
    EXPECT_EQ(getting_flat.get_likes(), user.get_likes());
}


TEST(DATABASE, ADD_FLATS)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    PGDataBase db(params);
    
    EXPECT_TRUE(db.connect_db() == true);
    
    int price_1 = 1000;
    std::string city_1 = "Moscow";
    std::string address_1 = "BMSTU, VK education";
    int rooms_1 = 10;
    int square_1 = 900;
    int floor_1 = 3;
    std::vector<std::string> photo_urls_1 = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro_1 =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes_1 = { 1, 2, 3 };
    Flat flat_1(price_1, city_1, address_1, rooms_1, square_1, floor_1, photo_urls_1, nearest_metro_1, likes_1);

        
    int price_2 = 8000;
    std::string city_2 = "Moscow";
    std::string address_2 = "BMSTU, not VK education";
    int rooms_2 = 100;
    int square_2 = 800;
    int floor_2 = 7;
    std::vector<std::string> photo_urls_2 = { "https://someurl.ru/image/1", "https://someurl.ru/image/2" }; 
    std::map<std::string, int> nearest_metro_2 =  { {"some_station_1", 200}, {"some_station_2", 300}, }
    std::vector<int> likes_2 = { 1, 9, 3 };
    Flat flat_2(price_2, city_2, address_2, rooms_2, square_2, floor_2, photo_urls_2, nearest_metro_2, likes_2);

    std::vector<Flat> flats = { flat_1, flat_2 };
    
    EXPECT_TRUE(db.add_flats(flats) == true);
    
    std::vector<int> ids = { 1, 2 };
    std::vector<Flat> getting_flats = get_flats(ids);
    
    for (int i = 0; i < flats.size(); i++)
    {
		EXPECT_EQ(getting_flats[i].get_price(), flats[i].get_price());
		EXPECT_EQ(getting_flats[i].get_city(), flats[i].get_city());
		EXPECT_EQ(getting_flats[i].get_address(), flats[i].get_address());
		EXPECT_EQ(getting_flats[i].get_rooms(), flats[i].get_rooms());
		EXPECT_EQ(getting_flats[i].get_square(), flats.get_square());
		EXPECT_EQ(getting_flats[i].get_photo_urls(), flats[i].get_photo_urls());
		EXPECT_EQ(getting_flats[i].get_nearest_metro(), flats[i].get_nearest_metro());
		EXPECT_EQ(getting_flats[i].get_likes(), flats[i].get_likes());
    }
}
