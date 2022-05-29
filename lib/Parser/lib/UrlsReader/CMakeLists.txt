add_library(UrlsReader src/UrlsReader.cpp)

target_include_directories(UrlsReader PUBLIC include)
target_link_libraries(UrlsReader CURL::libcurl)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()