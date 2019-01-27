// #include "HeplList.hpp"
template<class T>
T* HeplList<T>::add(const T& val) {

    T newVal = T(val);
    Cell<T> *newCell = new Cell<T>();
    newCell->setValue(newVal);
    newCell->setNext(nullptr);

    if (BaseList<T>::m_pHead == nullptr) {
        BaseList<T>::m_pHead = newCell;
        return newCell->getValue();
    }

    Cell<T> *listCell = BaseList<T>::m_pHead;
    Cell<T> *listCellPrevious = nullptr;
    while (listCell != nullptr) {
        listCellPrevious = listCell;
        listCell = listCell->getNext();
    }

    listCellPrevious->setNext(newCell);
    return newCell->getValue();
}
