#include "UrlsReader.h"

UrlsReader::UrlsReader(){
}

UrlsReader::~UrlsReader() {
}

std::vector<std::string> UrlsReader::set_urls(std::string &base_url, std::string &get_param_url, size_t pages) {
    std::string page;

    for (int i = 0; i < pages; i++) { // to do pages
        page = std::to_string(i + 1);
        std::string URL = base_url + get_param_url + page;
        URLS.push_back(URL);
    }
    return URLS;
}

std::vector<std::string> UrlsReader::parser_urls() {
    if (URLS.empty())
        return URLS;
    std::vector<std::string> otvet;
    for (int i = 0; i < URLS.size(); i++) {
        otvet.push_back(parser_page(URLS.at(i)));
    }
    return otvet;
}


static size_t write_data(char *ptr, size_t size, size_t nmemb, std::string *data) {
    if (data) {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    } else
        return 0;
}

std::string UrlsReader::parser_page(std::string url) {
    CURL *curl_handle;
    curl_handle = curl_easy_init();
    if (curl_handle == nullptr)
        return "FAIL_READ";
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

    std::string content;
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &content);

    CURLcode res = curl_easy_perform(curl_handle);
    if (res)
        return "FAIL_READ";
    curl_easy_cleanup(curl_handle);
    return content;
}

