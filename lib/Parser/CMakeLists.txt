cmake_minimum_required(VERSION 3.16)
project(Parser)

set(CMAKE_CXX_STANDARD 14)

#if(WITH_TESTS OR WITH_SANITIZERS OR WITH_COVERAGE)
#    enable_testing()
#    find_package(GTest REQUIRED)
#    set(BUILD_TESTS ON)
#endif()

enable_testing()
find_package(GTest REQUIRED)
set(BUILD_TESTS ON)

find_package(CURL)
find_package(RapidJSON)
find_package(Boost)

add_executable(Parser src/main.cpp)

target_link_libraries(Parser ArgumentsParser)

add_subdirectory(lib/JsonReader)
add_subdirectory(lib/UrlsReader)
add_subdirectory(lib/ArgumentsParser)