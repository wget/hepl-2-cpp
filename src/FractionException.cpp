#include "FractionException.hpp"

FractionException::FractionException()
    : HeplBaseException(), m_code(-1) {
}

FractionException::FractionException(const HeplString& msg, int code)
    : HeplBaseException(msg), m_code(code) {
}

FractionException::FractionException(const char* msg, int code)
    : HeplBaseException(msg), m_code(code) {
}

int FractionException::getCode() const {
    return m_code;
}

void FractionException::setCode(int code) {
    m_code = code;
}

const int FractionException::ERROR_DENOMINATOR_NUL = 0;
const int FractionException::ERROR_DIVIDE_BY_ZERO = 1;
