// #include "BaseList.hpp"

template<class T>
BaseList<T>::BaseList()
    : m_pHead(nullptr) {
}

template<class T>
BaseList<T>::BaseList(BaseList& baseList)
    : m_pHead(nullptr) {

    if (baseList.m_pHead == nullptr) {
        return;
    }

    m_pHead = new Cell<T>();
    m_pHead->setValue(*(baseList.m_pHead->getValue()));
    m_pHead->setNext(nullptr);

    Cell<T> *currentCell = nullptr;
    Cell<T> *nextCell = nullptr;

    currentCell = m_pHead;
    nextCell = baseList.m_pHead->getNext();

    // Inspiration taken from: https://stackoverflow.com/q/7811893/3514658
    while (nextCell != nullptr) {
        currentCell->setNext(new Cell<T>());
        currentCell = currentCell->getNext();

        currentCell->setValue(*(nextCell->getValue()));
        nextCell = nextCell->getNext();
    }
    currentCell->setNext(nullptr);
}

template<class T>
BaseList<T>::~BaseList() {
    Cell<T> *baseListCell = m_pHead;
    Cell<T> *baseListCellCurrent = nullptr;
    while (baseListCell != nullptr) {
        baseListCellCurrent = baseListCell;
        baseListCell = baseListCell->getNext();
        delete baseListCellCurrent;
    }
    baseListCell = nullptr;
}

template<class T>
bool BaseList<T>::isEmpty() const {
    return m_pHead == nullptr ? true : false;
}

template<class T>
size_t BaseList<T>::getNumberItems() const {

    Cell<T> *baseListCell = m_pHead;
    size_t i = 0;
    while (baseListCell != nullptr) {
        baseListCell = baseListCell->getNext();
        i++;
    }
    return i;
}

template<class T>
void BaseList<T>::display() const {
    Cell<T> *baseListCell = m_pHead;
    size_t i = 0;
    while (baseListCell != nullptr) {
        baseListCell->display();
        baseListCell = baseListCell->getNext();
        i++;
    }
}

template<class T>
BaseList<T>& BaseList<T>::operator=(BaseList const& baseList) {

    // TODO: Effacer la liste ou réécrire dessus
    //
    if (baseList.m_pHead == nullptr) {
        return *this;
    }

    Cell<T> *newCell = new Cell<T>();
    Cell<T> *newCellStart = newCell;
    Cell<T> *baseListCell = baseList.m_pHead;

    while (baseListCell != nullptr) {
        newCell->setValue(*(baseListCell->getValue()));
        if (baseListCell->getNext() == nullptr) {
            newCell->setNext(baseListCell->getNext());
        } else {
            newCell->setNext(new Cell<T>());
        }
        newCell = newCell->getNext();
        baseListCell = baseListCell->getNext();
    }
    m_pHead = newCellStart;
    return *this;
}

template<class T>
T* BaseList<T>::operator[](size_t itemNumber) {
    Cell<T> *baseListCell = m_pHead;
    size_t i = 0;
    while (baseListCell != nullptr && i != itemNumber) {
        baseListCell = baseListCell->getNext();
        i++;
    }

    if (baseListCell == nullptr) {
        return nullptr;
    }

    return baseListCell->getValue();
}
