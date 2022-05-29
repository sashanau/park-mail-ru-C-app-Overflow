#include "gtest/gtest.h"
#include "UrlsReader.h"
#include <vector>

TEST(UrlsReader_set_urls, UrlsReader_set_urls) {
    UrlsReader readUrls = UrlsReader();
    std::string url = "https://www.domofond.ru", base = "?Page=";
    std::vector<std::string> urls_set = readUrls.set_urls(url, base, 10);
    for (int i = 0; i < urls_set.size(); i++) {
        EXPECT_TRUE(urls_set.at(i) == (url + base + std::to_string(i + 1)));
    }
}


TEST(UrlsReader_parser_urls, UrlsReader_parser_urls) {
    UrlsReader readUrls = UrlsReader();
    std::string url = "https://www.domofond.ru", base = "?Page=";
    readUrls.set_urls(url, base, 1);
    std::vector<std::string> context = readUrls.parser_urls();
    EXPECT_TRUE(context.empty() == false);
}

TEST(UrlsReader_parser_urls, UrlsReader_parser_urls_error) {
    UrlsReader readUrls = UrlsReader();
    std::string url = " ", base = " ";
    readUrls.set_urls(url, base, 1);
    std::vector<std::string> context = readUrls.parser_urls();
    EXPECT_TRUE(context.at(0) == "FAIL_READ");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



