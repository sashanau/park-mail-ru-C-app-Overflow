add_executable(JsonReader_test src/JsonReader_test.cpp)

target_link_libraries(JsonReader_test JsonReader UrlsReader GTest::GTest)
add_test(NAME JsonReader_test COMMAND JsonReader_test)