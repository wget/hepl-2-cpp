#ifndef LISTENER_HPP_DEFINED
#define LISTENER_HPP_DEFINED

#include "./lib/utils/src/HeplString.hpp"

class Listener {

    public:
        virtual void actionButton(const HeplString name) = 0;
};

#endif // LISTENER_HPP_DEFINED
