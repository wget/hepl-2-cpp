#ifndef BASEEXCEPTION_HPP_INCLUDED
#define BASEEXCEPTION_HPP_INCLUDED

#include "HeplString.hpp"

class BaseException {

    protected:
        HeplString msg;

    public:
        BaseException();
        BaseException(const HeplString& msg);
        BaseException(const char* msg);
        HeplString what() const;
};

#endif // BASEEXCEPTION_HPP_INCLUDED
