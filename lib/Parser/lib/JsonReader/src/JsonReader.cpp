#include "JsonReader.h"

JsonReader::JsonReader(std::vector<std::string> context) :
    context(context)
{
}

JsonReader::~JsonReader() {
}

std::vector<std::shared_ptr<rapidjson::Document>> JsonReader::strs_to_json() {
    for (auto &con: context) {
        std::shared_ptr<rapidjson::Document> document = std::make_shared<rapidjson::Document>();
        document->Parse(con.c_str());
        documents.push_back(document);
    }
    return documents;
}

std::vector<std::string> JsonReader::find_json(const std::string& param_find) {
    boost::regex xRegEx(param_find);
    boost::smatch xResults;
    for (auto &con: context) {
        boost::regex_search(con, xResults, xRegEx);
        con = xResults[0];
    }
    return context;
}

