#include "gtest/gtest.h"
#include "JsonReader.h"
#include "UrlsReader.h"
#include "rapidjson/document.h"
#include <vector>


TEST(JsonReader_find_json, JsonReader_find_json) {
    std::string json = "<html>{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}</html>";
    std::string json_otvet = "{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json);
    JsonReader jsonReader = JsonReader(vector_json);
    std::vector<std::string> a = jsonReader.find_json("{\"hello\"(.*)]}");
    EXPECT_TRUE(a.at(0) == json_otvet);
}

TEST(JsonReader_find_json, JsonReader_find_json_error) {
    std::string json = "<html>{\"hello\": \"world\","
                       " \"t\": true,"
                       " \"f\": false,"
                       " \"n\": \"null\","
                       " \"i\": \"123\","
                       " \"pi\": 3.1416,"
                       " \"a\": [1, 2, 3, 4]}</html>";
    std::string json_otvet = "{\"hello\": \"world\","
                             " \"t\": true,"
                             " \"f\": false,"
                             " \"n\": \"null\","
                             " \"i\": \"123\","
                             " \"pi\": 3.1416,"
                             " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json);
    JsonReader jsonReader = JsonReader(vector_json);
    std::vector<std::string> a = jsonReader.find_json("8789879"); // ошибочный поиск
    EXPECT_TRUE(a.at(0).empty() == true);
}

TEST(Read_Json_strs_to_json, Read_Json_strs_to_json) {
    std::string json_otvet = "{\"hello\": \"world\","
                             " \"t\": true,"
                             " \"f\": false,"
                             " \"i\": 123,"
                             " \"pi\": 3.1416,"
                             " \"a\": [1, 2, 3, 4]}";
    std::vector<std::string> vector_json;
    vector_json.push_back(json_otvet);
    JsonReader jsonReader = JsonReader(vector_json);
    std::vector<std::shared_ptr<rapidjson::Document>> test_doc = jsonReader.strs_to_json();
    std::shared_ptr<rapidjson::Document> otvet = test_doc.at(0);
    EXPECT_TRUE((*otvet)["hello"] == "world");
    EXPECT_TRUE((*otvet)["t"] == true);
    EXPECT_TRUE((*otvet)["f"] == false);
    EXPECT_TRUE((*otvet)["i"] == 123);
    EXPECT_TRUE((*otvet)["pi"] == 3.1416);
    EXPECT_TRUE((*otvet)["a"][0] == 1);
    EXPECT_TRUE((*otvet)["a"][1] == 2);
    EXPECT_TRUE((*otvet)["a"][2] == 3);
    EXPECT_TRUE((*otvet)["a"][3] == 4);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



