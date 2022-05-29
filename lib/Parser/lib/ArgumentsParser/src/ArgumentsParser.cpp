#include "ArgumentsParser.h"
#include "sqlite_database.h"

ArgumentsParser::ArgumentsParser(const std::string &base_url, const std::string &get_param, const size_t page_size, const std::string &name_db) :
    base_url(base_url),
    get_param(get_param),
    page_size(page_size),
    name_db(name_db)
{
    sqLiteDataBase = std::make_shared<SQLiteDataBase>(name_db);
}

ArgumentsParser::~ArgumentsParser() {
}

std::vector<std::string> ArgumentsParser::URLS_to_str() {
    UrlsReader urlsReader = UrlsReader();
    urlsReader.set_urls(base_url, get_param, page_size);
    std::vector<std::string> temp = urlsReader.parser_urls();
    context = temp;
    return temp;
}

std::vector<std::shared_ptr<rapidjson::Document>> ArgumentsParser::str_to_json(std::string &find_param) {
    JsonReader jsonReader = JsonReader(context);
    jsonReader.find_json(find_param);
    std::vector<std::shared_ptr<rapidjson::Document>> json = jsonReader.strs_to_json();
    jsons = json;
    return jsons;
}

size_t ArgumentsParser::json_to_db() {
    std::string title = "ERROR";
    int price = -1;
    int priceArea = -1;
    std::string address = "ERROR";
    std::string description = "ERROR";
    std::string metro = "ERROR";
    std::string propertyType = "ERROR";
    int floor = -1;
    int max_floor = -1;
    std::string photo = "ERROR";
    for (int i = 0; i < jsons.size(); i++) {
        std::shared_ptr<rapidjson::Document> document = (jsons)[i];
        if ((*document).HasMember("itemsState")) {
            if ((*document)["itemsState"].HasMember("items")) {
                rapidjson::Value elemenst;
                elemenst = (*document)["itemsState"]["items"];
                if (elemenst.Size() > 0) {
                    for (int j = 0; j < elemenst.Size(); j++) {
                        if (elemenst[j]["title"].IsString())
                            title = elemenst[j]["title"].GetString();
                        if (elemenst[j]["priceValue"].IsInt())
                            price = elemenst[j]["priceValue"].GetInt();
                        if (elemenst[j]["pricePerAreaValue"].IsInt())
                            priceArea = elemenst[j]["pricePerAreaValue"].GetInt();
                        if (elemenst[j]["address"].IsString())
                            address = elemenst[j]["address"].GetString();
                        if (elemenst[j]["description"].IsString())
                            description = elemenst[j]["description"].GetString();
                        if (elemenst[j].HasMember("station"))
                            if (elemenst[j]["station"].HasMember("name"))
                                if (elemenst[j]["station"]["name"].IsString())
                                    metro = elemenst[j]["station"]["name"].GetString();
                        if (elemenst[j]["propertyType"].IsString())
                            propertyType = elemenst[j]["propertyType"].GetString();
                        if (elemenst[j]["floorInt"].IsInt())
                            floor = elemenst[j]["floorInt"].GetInt();
                        if (elemenst[j]["floorAreaCalculated"].IsInt())
                            max_floor = elemenst[j]["floorAreaCalculated"].GetInt();
                        if (elemenst[j].HasMember("thumbnailUrls"))
                            if (elemenst[j]["thumbnailUrls"].IsArray())
                                if (elemenst[j]["thumbnailUrls"][0]["url"].IsString())
                                    photo = elemenst[j]["thumbnailUrls"][1]["url"].GetString();
                        FlatParams params = FlatParams(title,
                                         price,
                                         priceArea,
                                         address,
                                         description,
                                         metro,
                                         propertyType,
                                         floor,
                                         max_floor,
                                         photo);
                        Flat flat = Flat((FlatParams &)params);
                        sqLiteDataBase->add_flat(flat);
                    }
                }
            }
        }
    }
    return 1;
}

