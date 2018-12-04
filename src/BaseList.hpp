#ifndef BASELIST_HPP_INCLUDED
#define BASELIST_HPP_INCLUDED

#include <cstddef>
#include <iostream>
#include "Cell.hpp"

template<class T>
class BaseListIterator;

template<class T>
class BaseList {

    protected:
        Cell<T> *m_pHead;

    public:
        BaseList();
        BaseList(BaseList& baselist);
        virtual ~BaseList();
        bool isEmpty() const;
        size_t getNumberItems() const;
        virtual void display() const;
        // Pure virtual method
        virtual T* add(T const& val) = 0;
        BaseList& operator=(BaseList const& baseList);
        T& operator[](size_t i);
        friend class BaseListIterator<T>;
};

#include "BaseList.ipp"
#include "BaseListIterator.hpp"

#endif // BASELIST_HPP_INCLUDED
