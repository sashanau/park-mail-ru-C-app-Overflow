#ifndef __GETTRAVELTIME_H__
#define __GETTRAVELTIME_H__

#include <vector>
#include <string>
#include <curl/curl.h>


class TravelTimeGetter{
public:
    std::vector<int> make_request(const std::vector<std::string>& origins, const std::string& dest);
private:
    std::string get_encoded_request(CURL* curl, const std::vector<std::string>& origins, const std::string& dest);
    std::string send_request(const std::vector<std::string>& origins, const std::string& dest);
};

#endif
