add_executable(test_datalib src/test_database_params.cpp
                            src/test_flat.cpp
                            src/test_pg_database.cpp
                            src/test_user.cpp)

target_link_libraries(test_datalib database_params
                                   flat
                                   pg_database
                                   user
                                   GTest::Main)
add_test(NAME test_datalib COMMAND test_datalib)