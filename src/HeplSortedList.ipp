template<class T>
T* HeplSortedList<T>::add(T const& val) {

    T *newVal = new T(val);
    Cell<T> *newCell = new Cell<T>();
    newCell->setValue(*newVal);
    newCell->setNext(nullptr);

    if (BaseList<T>::m_pHead == nullptr) {
        BaseList<T>::m_pHead = newCell;
        return newVal;
    }

    if (*newVal <= *(BaseList<T>::m_pHead->getValue())) {
        newCell->setNext(BaseList<T>::m_pHead);
        BaseList<T>::m_pHead = newCell;
        return newVal;
    }

    Cell<T> *listCell = BaseList<T>::m_pHead;
    Cell<T> *listCellPrevious = BaseList<T>::m_pHead;
    while (listCell->getNext() != nullptr && val > *(listCell->getValue())) {
        listCellPrevious = listCell;
        listCell = listCell->getNext();
    }

    if (val > *(listCell->getValue())) {
        listCell->setNext(newCell);
        return newVal;
    }

    listCellPrevious->setNext(newCell);
    newCell->setNext(listCell);

    return newVal;
}
