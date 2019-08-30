#ifndef FRACTIONEXCEPTION_HPP_DEFINED
#define FRACTIONEXCEPTION_HPP_DEFINED

#include "./lib/src/HeplBaseException.hpp"
#include "Fraction.hpp"

class FractionException : public HeplBaseException {

    private:
        int m_code;

    public:
        FractionException();
        // We would have preferred to pass a const color reference instead but
        // since we are initializing a class member, we are losing the const
        // qualifier and C++ prevents from loosing it.
        FractionException(const HeplString& msg, int code);
        FractionException(const char* msg, int code);

        int getCode() const;
        void setCode(int code);

        // Static attributes
        static const int ERROR_DENOMINATOR_NUL;
        static const int ERROR_DIVIDE_BY_ZERO;
};

#endif // FRACTIONEXCEPTION_HPP_DEFINED
