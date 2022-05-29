cmake_minimum_required(VERSION 3.16)
project(Selector)

add_library(Selector src/FlatSelector.cpp src/JsonParser.cpp src/TravelTimeGetter.cpp)

find_package(CURL REQUIRED)
find_package(RapidJSON REQUIRED)
target_include_directories(Selector PRIVATE ${RAPIDJSON_INCLUDE_DIR})
target_include_directories(Selector PUBLIC include)

target_link_libraries(Selector CURL::libcurl datalib)
