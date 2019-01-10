template<class T>
T* HeplStack<T>::add(const T& val) {

    T *newVal = new T(val);
    Cell<T> *newCell = new Cell<T>();
    newCell->setValue(*newVal);
    newCell->setNext(this->m_pHead);
    this->m_pHead = newCell;
    return newVal;
}

template<class T>
void HeplStack<T>::push(const T& val) {
   this->add(val); 
}

template<class T>
T& HeplStack<T>::top() const {

    if (this->m_pHead == nullptr) {
        throw new HeplStackEmptyException();
    }
    return *(this->m_pHead->getValue());
}

template<class T>
T& HeplStack<T>::pop() {

    if (this->m_pHead == nullptr) {
        throw new HeplStackEmptyException();
    }

    Cell<T> *cellToRemove = this->m_pHead;
    T *newVal = new T(*(cellToRemove->getValue()));
    this->m_pHead = cellToRemove->getNext();
    delete cellToRemove;
    return *newVal;
}
