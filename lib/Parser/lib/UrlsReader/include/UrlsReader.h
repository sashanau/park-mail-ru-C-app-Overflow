#ifndef PARSER_URLSREADER_H
#define PARSER_URLSREADER_H

#include "IUrlsReader.h"
#include <curl/curl.h>


class UrlsReader : public IUrlsReader {
public:
    UrlsReader();
    ~UrlsReader();

    std::vector<std::string> set_urls(std::string & base_url, std::string &get_param, size_t pages) override;
    std::vector<std::string> parser_urls() override;

private:
    static std::string parser_page(std::string);
    std::vector<std::string> URLS;
};

#endif //PARSER_URLSREADER_H
