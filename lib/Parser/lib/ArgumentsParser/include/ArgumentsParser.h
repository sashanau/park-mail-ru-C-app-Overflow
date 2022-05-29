#ifndef PARSER_APARTMENTS_H
#define PARSER_APARTMENTS_H

#include <vector>
#include <curl/curl.h>
#include "JsonReader.h"
#include "UrlsReader.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "sqlite_database.h"


class ArgumentsParser{
public:
    ArgumentsParser(const std::string &base_url, const std::string &get_param, const size_t page_size, const std::string &name_db);
    ~ArgumentsParser();
    std::vector<std::string> URLS_to_str();
    std::vector<std::shared_ptr<rapidjson::Document>> str_to_json(std::string &find_param);
    size_t json_to_db();

private:
    size_t page_size;
    std::string base_url;
    std::string get_param;
    std::string name_db;
    std::vector<std::string> context;
    std::vector<std::shared_ptr<rapidjson::Document>> jsons;
    std::shared_ptr<SQLiteDataBase> sqLiteDataBase;
};

#endif //PARSER_APARTMENTS_H
