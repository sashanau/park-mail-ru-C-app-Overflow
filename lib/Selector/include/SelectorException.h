#ifndef __SELECTOR_EXCEPTION_H__
#define __SELECTOR_EXCEPTION_H__


#include <string>
#include <exception>


class SelectorException: public std::exception {
public:
    SelectorException(const std::string &filename, int line, const char *time, const std::string &message){
    error = "Error! " + message + "\n" + time + "Filename: " + filename + ", line # " + std::to_string(line);
    }
    [[nodiscard]] const char *what() const noexcept {
    return error.c_str();
    }

protected:
    std::string error;
};

#endif