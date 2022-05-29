#include "SelectorException.h"
#include "TravelTimeGetter.h"
#include "JsonParser.h"

#include <curl/curl.h>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

const std::string API_KEY = "AIzaSyCYs2rbbVWwrEe6LBLcpnLuykpFUSJBUKk";


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string TravelTimeGetter::get_encoded_request(CURL *curl, const std::vector<std::string>& origins, const std::string& dest){

	std::string enc_dest = curl_easy_escape(curl, dest.c_str(), dest.length());
    std::string enc_request_string =  "?destinations=" + enc_dest;

	std::string enc_origins;

	for(std::string origin : origins) {
		enc_origins +=  origin + "|";
	}
	enc_origins.pop_back();
	enc_origins = curl_easy_escape(curl, enc_origins.c_str(), enc_origins.length());
	enc_request_string += "&origins=" + enc_origins;
	
	enc_request_string += "&key=";
	enc_request_string += API_KEY;

	return enc_request_string;
}

std::string TravelTimeGetter::send_request(const std::vector<std::string>& origins, const std::string& dest){
	CURLcode res;
	std::string json;
	CURL* curl = curl_easy_init();

	const std::string enc_request = "https://maps.googleapis.com/maps/api/distancematrix/json" + get_encoded_request(curl, origins, dest);
	curl_easy_setopt(curl, CURLOPT_URL, enc_request.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &json);

  	res = curl_easy_perform(curl);

 	curl_easy_cleanup(curl);

	if(res != CURLE_OK){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "No reply");
		json = "";
	}

	 return json;
}


std::vector<int> TravelTimeGetter::make_request(const std::vector<std::string>& origins, const std::string& dest){
	JsonParser parser;

	std::string json = send_request(origins, dest);
	
    if(json.empty()){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "TravelTimeGetter::make_request - api err");
        return {};
    }
	std::vector<int> travel_time = {};
	try{
		travel_time = parser.parse_json(json);
	}
	catch(...){
        time_t time_now = time(nullptr);
		throw SelectorException(__FILE__, __LINE__, ctime(&time_now), "TravelTimeGetter::make_request - parsing error");
        return {};
    }

    return travel_time;
}
