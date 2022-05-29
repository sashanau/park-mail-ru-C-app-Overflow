add_library(JsonReader src/JsonReader.cpp)

target_include_directories(JsonReader PUBLIC include)
target_link_libraries(JsonReader)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()