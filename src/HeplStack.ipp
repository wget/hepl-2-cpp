template<class T>
T* HeplStack<T>::add(const T& val) {

    T newVal(val);
    Cell<T> *newCell = new Cell<T>();
    newCell->setValue(newVal);
    newCell->setNext(BaseList<T>::m_pHead);
    BaseList<T>::m_pHead = newCell;
    return newCell->getValue();
}

template<class T>
void HeplStack<T>::push(const T& val) {
    add(val); 
}

template<class T>
T HeplStack<T>::top() const {

    if (BaseList<T>::m_pHead == nullptr) {
        throw new HeplStackEmptyException();
    }
    return *(BaseList<T>::m_pHead->getValue());
}

template<class T>
T HeplStack<T>::pop() {

    if (BaseList<T>::m_pHead == nullptr) {
        throw new HeplStackEmptyException();
    }

    T newVal(*(BaseList<T>::m_pHead->getValue()));
    Cell<T> *cellToRemove = BaseList<T>::m_pHead;
    BaseList<T>::m_pHead = BaseList<T>::m_pHead->getNext();
    delete cellToRemove;
    return newVal;
}
