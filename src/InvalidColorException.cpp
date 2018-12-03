#include "InvalidColorException.hpp"

InvalidColorException::InvalidColorException()
    : BaseException(), m_color(new Color()) {
}

InvalidColorException::InvalidColorException(const HeplString& msg, const Color* color)
    : BaseException(msg), m_color(color) {
}

InvalidColorException::InvalidColorException(const char* msg, const Color* color)
    : BaseException(msg), m_color(color) {
}

bool InvalidColorException::isRedValid() const {
    if (m_color->getRed() < 0 || m_color->getRed() > 255) {
        return false;
    }
    return true;
}

bool InvalidColorException::isGreenValid() const {
    if (m_color->getGreen() < 0 || m_color->getGreen() > 255) {
        return false;
    }
    return true;
}

bool InvalidColorException::isBlueValid() const {
    if (m_color->getBlue() < 0 || m_color->getBlue() > 255) {
        return false;
    }
    return true;
}
