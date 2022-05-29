#include "db_exception.h"


BaseError::BaseError(const std::string &filename, const int line, const char *time, const std::string &message) {
    error = "Error! " + message + "\n" + time + "Filename: " + filename + ", line # " + std::to_string(line);
}


[[nodiscard]] const char* BaseError::what() const noexcept {
    return error.c_str();
}


ConnectionError::ConnectionError(const std::string &filename, const int line,
                                 const char *time, const std::string &message):
        BaseError(filename, line, time,
                  "Incorrect connection to database. Please check your db file: " + message) {};
