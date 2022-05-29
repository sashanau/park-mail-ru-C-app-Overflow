add_library(datalib src/sqlite_database.cpp
                    src/db_exception.cpp
                    src/flat_params.cpp
                    src/flat.cpp)

target_include_directories(datalib PUBLIC include)

find_package(SQLite3 REQUIRED)
target_link_libraries(datalib sqlite3)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()