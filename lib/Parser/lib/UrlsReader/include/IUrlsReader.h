#ifndef PARSER_IURLSREADER_H
#define PARSER_IURLSREADER_H

#include <iostream>
#include <vector>

class IUrlsReader {
public:
    virtual std::vector<std::string> set_urls(std::string &, std::string &, size_t pages) = 0;
    virtual std::vector<std::string> parser_urls() = 0;
};

#endif //PARSER_IURLSREADER_H
