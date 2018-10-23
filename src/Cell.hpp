#ifndef CELL_HPP_INCLUDED
#define CELL_HPP_INCLUDED

#include <iostream>

template<class T>
class Cell {

    private:
        T m_value;
        Cell<T> *m_pNext;
    public:
        Cell<T>();
        Cell<T>(T value, Cell<T> *pNext);
        T* getValue();
        Cell<T>* getNext() const;
        void setValue(T newValue);
        void setNext(Cell<T> *newNext);
        void display() const;
};

#include "Cell.ipp"

#endif // CELL_HPP_INCLUDED
