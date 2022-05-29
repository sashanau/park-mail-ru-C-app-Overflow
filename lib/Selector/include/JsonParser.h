#ifndef __PARSEJSON_H__
#define __PARSEJSON_H__

#include <vector>
#include <string>

class JsonParser{
public:
    std::vector<int> parse_json(const std::string& json);
};

#endif
