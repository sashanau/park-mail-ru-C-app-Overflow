#include <iostream>
#include "ArgumentsParser.h"


// popen use

int main() {
    std::string base = "https://www.domofond.ru/arenda-kvartiry-moskva-c3584?";
    std::string get = "Page=";
    std::string name_db = "overflow.db";
    std::string param = "{\"itemsState\":(.*)}}";

    ArgumentsParser parser = ArgumentsParser(base, get, 2, name_db);
    parser.URLS_to_str();
    parser.str_to_json(param);
    size_t error = parser.json_to_db();
    if (error == 0)
        return 1;
    return 0;
}
