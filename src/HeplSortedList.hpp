#ifndef HEPLSORTEDLIST_HPP_DEFINED
#define HEPLSORTEDLIST_HPP_DEFINED

#include <cstddef>
#include "BaseList.hpp"
#include "Cell.hpp"

template<class T>
class HeplSortedList: public BaseList<T> {

    public:
        // Default constructor and copy constructor are automatically
        // inherited.

        T* add(T const& val);
};

#include "HeplSortedList.ipp"

#endif // HEPLSORTEDLIST_HPP_DEFINED
