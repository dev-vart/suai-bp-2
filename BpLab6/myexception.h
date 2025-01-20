#pragma once
#include <exception>
#include <string>

class MyException : public std::exception {
   public:
    explicit MyException(const std::string& message, bool fatal_error)
        : fatal_error(fatal_error), msg(message) {}

    const char* what() const noexcept override { return msg.c_str(); }

    bool fatal_error;

   private:
    std::string msg;
};