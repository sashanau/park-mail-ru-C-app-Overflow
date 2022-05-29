#include <gtest/gtest.h>

extern "C"
{
    #include "../../../../extra/database_params.h"
}


TEST(PARAMS_TEST, GET_HOST)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    
    EXPECT_EQ(host, params.get_host());
}


TEST(PARAMS_TEST, GET_PORT)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    
    EXPECT_EQ(port, params.get_port());
}


TEST(PARAMS_TEST, GET_NAME)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    
    EXPECT_EQ(name, params.get_name());
}


TEST(PARAMS_TEST, GET_USER)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    
    EXPECT_EQ(user, params.get_user());
}


TEST(PARAMS_TEST, GET_PASSWORD)
{    
    std::string host = "localhost";
    int port = 5000;
    std::string name = "postgres";
    std::string user = "overflow";
    std::string password = "overflow";
    
    DataBaseParams params(host, port, name, user, password);
    
    EXPECT_EQ(password, params.get_password());
}