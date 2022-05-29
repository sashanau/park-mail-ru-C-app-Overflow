#ifndef __DB_EXCEPTION_H__
#define __DB_EXCEPTION_H__


#include <string>
#include <exception>


class BaseError: public std::exception {
public:
    BaseError(const std::string &filename, int line, const char *time, const std::string &message);
    [[nodiscard]] const char *what() const noexcept final;

protected:
    std::string error;
};


class ConnectionError: public BaseError {
public:
    ConnectionError(const std::string &filename, int line, const char *time, const std::string &message);
};


#endif  // __DB_EXCEPTION_H__
