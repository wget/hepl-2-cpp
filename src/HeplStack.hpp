#ifndef HEPLSTACK_HPP_DEFINED
#define HEPLSTACK_HPP_DEFINED

#include "BaseException.hpp"
#include "BaseList.hpp"
#include "Cell.hpp"
#include <iostream>

template<class T>
class HeplStack : public BaseList<T> {

    public:
        // Default constructor and copy constructor are automatically
        // inherited.
        T* add(const T& val);
        void push(const T& val);
        T top() const;
        T pop();
};

class HeplStackEmptyException: BaseException {
    using BaseException::BaseException;
};

#include "HeplStack.ipp"

#endif // HEPLSTACK_HPP_DEFINED
