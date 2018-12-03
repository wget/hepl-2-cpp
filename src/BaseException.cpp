#include "BaseException.hpp"

BaseException::BaseException() {
}

BaseException::BaseException(const HeplString& msg)
    : msg(msg) {
}

BaseException::BaseException(const char* msg)
    : msg(msg) {
}

HeplString BaseException::what() const {
    return msg;
}
