#include "SelectorException.h"
#include "JsonParser.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

std::vector<int> JsonParser::parse_json(const std::string& json){
	rapidjson::Document d;

    d.Parse(json.c_str());
	size_t size = 0;

	using rapidjson::Value;
	Value elemenst;
	
	if(!d.HasMember("rows")) {
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
		return {};
	}

	if(!d.HasMember("rows")) {
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
		return {};
	}

	elemenst = d["rows"];
	size = elemenst.Size();
	
	std::vector<int> result;

	for(size_t i = 0; i < size; i++){
		if(!elemenst[i].HasMember("elements")) {
			time_t time_now = time(nullptr);
			throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
			return {};
		}
		const Value & array = elemenst[i]["elements"];

		if(!array.IsArray()) {
			time_t time_now = time(nullptr);
			throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
			return {};
		}
		if(!array[0].HasMember("duration")) {
			time_t time_now = time(nullptr);
			throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
			return {};
		}
		const Value &duration = array[0]["duration"];

		if(!duration.HasMember("value")) {
			time_t time_now = time(nullptr);
			throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "error while parsing json");
			return {};
		}
		result.push_back(duration["value"].GetInt());
	}
    return result;
}
