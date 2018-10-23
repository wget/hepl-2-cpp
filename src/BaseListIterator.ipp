template<class T>
BaseListIterator<T>::BaseListIterator(BaseList<T>& list)
    : m_list(list), m_currentCell(list.m_pHead) {
}

template<class T>
bool BaseListIterator<T>::end() const {
    return m_currentCell == nullptr ? true : false;
}

template<class T>
void BaseListIterator<T>::reset() {
    m_currentCell = m_list.m_pHead;
}

template<class T>
bool BaseListIterator<T>::operator++() {
    if (m_currentCell == nullptr) {
        return false;
    }

    m_currentCell = m_currentCell->getNext();
    return true;
}

template<class T>
bool BaseListIterator<T>::operator++(int) {
    return operator++();
}

template<class T>
BaseListIterator<T>::operator T() const {
    T newValue = *(m_currentCell->getValue());
    return newValue;
}

template<class T>
T* BaseListIterator<T>::operator&(void) {
    return m_currentCell->getValue();
}

template<class T>
T* BaseListIterator<T>::operator*(void) {
    return m_currentCell->getValue();
}

template<class T>
T BaseListIterator<T>::remove() {
    Cell<T> *cell = m_list.m_pHead;
    Cell<T> *previousCell = m_list.m_pHead;
    while (cell != nullptr) {
        if (*(cell->getValue()) == *(m_currentCell->getValue())) {
            previousCell->setNext(cell->getNext());
            T cellValue = *(m_currentCell->getValue());
            (*this)++;
            delete cell;
            return cellValue;
        }
        previousCell = cell;
        cell = cell->getNext();
    }

    Cell<T> newCell;
    return *(newCell.getValue());
}
