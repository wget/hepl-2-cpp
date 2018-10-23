template<class T>
Cell<T>::Cell()
    : m_pNext(nullptr) {
}

template<class T>
Cell<T>::Cell(T value, Cell<T> *pNext)
    : m_value(value), m_pNext(pNext) {
}

// Needed to be a non const pointer for the add method in the list
template<class T>
T* Cell<T>::getValue() {
    return &m_value;
}

template<class T>
Cell<T>* Cell<T>::getNext() const {
    return m_pNext;
}

template<class T>
void Cell<T>::setValue(T newValue) {
    m_value = newValue;
}

template<class T>
void Cell<T>::setNext(Cell<T> *newNext) {
    m_pNext = newNext;
}

template<class T>
void Cell<T>::display() const {
    std::cout << m_value << std::endl;
}
