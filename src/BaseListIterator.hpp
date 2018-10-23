#ifndef BASELISTITERATOR_HPP_INCLUDED
#define BASELISTITERATOR_HPP_INCLUDED

#include <cstddef>
#include "BaseList.hpp"
#include "HeplList.hpp"
#include "HeplSortedList.hpp"
#include "Cell.hpp"

template<class T>
class BaseListIterator {

    private:
        BaseList<T>& m_list;
        Cell<T> *m_currentCell;

    public:
        BaseListIterator(BaseList<T>& list);
        bool end() const;
        void reset();
        bool operator++();
        bool operator++(int);
        operator T() const;
        T* operator&(void);
        T* operator*(void);
        T remove();
};

#include "BaseListIterator.ipp"

#endif // BASELISTITERATOR_HPP_INCLUDED
