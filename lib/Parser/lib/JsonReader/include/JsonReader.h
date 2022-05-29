#ifndef PARSER_JSONREADER_H
#define PARSER_JSONREADER_H
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <boost/regex.hpp>
#include <vector>

class JsonReader{
public:
    JsonReader(std::vector<std::string>);
    ~JsonReader();
    std::vector<std::shared_ptr<rapidjson::Document>> strs_to_json();
    std::vector<std::string> find_json(const std::string& param_find);

private:
    std::vector<std::string> context;
    std::vector<std::shared_ptr<rapidjson::Document>> documents;
};

#endif //PARSER_JSONREADER_H
