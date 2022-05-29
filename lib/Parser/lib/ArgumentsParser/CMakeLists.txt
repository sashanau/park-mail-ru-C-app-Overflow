add_library(ArgumentsParser src/ArgumentsParser.cpp)

target_include_directories(ArgumentsParser PUBLIC include)
target_link_libraries(ArgumentsParser CURL::libcurl JsonReader UrlsReader datalib)
