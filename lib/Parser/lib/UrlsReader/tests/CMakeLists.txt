add_executable(UrlsReader_test src/UrlsReader_test.cpp)

target_link_libraries(UrlsReader_test UrlsReader GTest::GTest)
add_test(NAME UrlsReader_test COMMAND UrlsReader_test)