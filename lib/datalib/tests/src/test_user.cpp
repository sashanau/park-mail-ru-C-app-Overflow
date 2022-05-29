#include <gtest/gtest.h>

extern "C"
{
    #include "user.h"
}


TEST(USER_TEST, GET_FULL_NAME)
{    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 70, 90};
    
    User user(name, surname, address, age, city, likes);
    
    EXPECT_EQ(name + " " + surname, user.get_full_name());   
}


TEST(USER_TEST, GET_ADDRESS)
{    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 70, 90};
    
    User user(name, surname, address, age, city, likes);
    
    EXPECT_EQ(address, user.get_address());
}


TEST(USER_TEST, GET_AGE)
{    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 70, 90};
    
    User user(name, surname, address, age, city, likes);
    
    EXPECT_EQ(age, user.get_age());
}


TEST(USER_TEST, GET_CITY)
{    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 70, 90};
    
    User user(name, surname, address, age, city, likes);
    
    EXPECT_EQ(city, user.get_city());
}


TEST(USER_TEST, GET_LIKES)
{    
    std::string name = "Ilya";
    std::string surname = "Klimov";
    std::string address = "BMSTU, VK education";
    int age = 20;
    std::string city = "Moscow";
    std::vector<int> likes = { 1, 70, 90};
    
    User user(name, surname, address, age, city, likes);
    
    std::vector<int> getting_likes = user.get_likes();
    
    EXPECT_EQ(likes.size(), getting_likes.size());
    for (int i = 0; i < likes.size(); i++)
        EXPECT_EQ(likes[i], getting_likes[i]);
}

