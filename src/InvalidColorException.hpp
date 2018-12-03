#ifndef INVALIDCOLOREXCEPTION_HPP_DEFINED
#define INVALIDCOLOREXCEPTION_HPP_DEFINED

#include "BaseException.hpp"
#include "Color.hpp"

class InvalidColorException : public BaseException {

    private:
        const Color* m_color;

    public:
        InvalidColorException();
        // We would have preferred to pass a const color reference instead but
        // since we are initializing a class member, we are losing the const
        // qualifier and C++ prevents from loosing it.
        InvalidColorException(const HeplString& msg, const Color* color);
        InvalidColorException(const char* msg, const Color* color);

        bool isRedValid() const;
        bool isGreenValid() const;
        bool isBlueValid() const;
};

#endif // INVALIDCOLOREXCEPTION_HPP_DEFINED
