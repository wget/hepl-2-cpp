#ifndef HEPLLIST_HPP_INCLUDED
#define HEPLLIST_HPP_INCLUDED

#include <cstddef>
#include "BaseList.hpp"
#include "Cell.hpp"

template<class T>
class HeplList : public BaseList<T> {


    public:
        // Default constructor and copy constructor are automatically
        // inherited.

        T* add(const T& val);
};

#include "HeplList.ipp"

#endif // HEPLLIST_HPP_INCLUDED
