#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
private:
    T * vector;
    unsigned int vector_size;
    unsigned int vector_capacity;

    static T * copy(T *, unsigned int, unsigned int);
public:
    class iterator;
    class const_iterator;

    class iterator {
        friend class Container<T>;
    private:
        T * pointer;

        iterator(T * = nullptr);
    public:
        T & operator *() const;
        T & operator [](int) const;
        T * operator ->() const;

        iterator & operator ++();
        iterator operator ++(int);
        iterator & operator --();
        iterator operator --(int);
        iterator & operator +=(int);
        iterator & operator -=(int);
        iterator operator +(int) const;
        iterator operator -(int) const;

        bool operator ==(const const_iterator &) const;
        bool operator !=(const const_iterator &) const;
        bool operator <=(const const_iterator &) const;
        bool operator >=(const const_iterator &) const;
        bool operator <(const const_iterator &) const;
        bool operator >(const const_iterator &) const;
    };

    class const_iterator {
        friend class Container<T>;
    private:
        const T * pointer;

        const_iterator(const T * = nullptr);
    public:
        const_iterator(const iterator &);

        const T & operator *() const;
        const T & operator [](int) const;
        const T * operator ->() const;

        const_iterator & operator ++();
        const_iterator operator ++(int);
        const_iterator & operator --();
        const_iterator operator --(int);
        const_iterator & operator +=(int);
        const_iterator & operator -=(int);
        const_iterator operator +(int) const;
        const_iterator operator -(int) const;

        bool operator ==(const const_iterator &) const;
        bool operator !=(const const_iterator &) const;
        bool operator <=(const const_iterator &) const;
        bool operator >=(const const_iterator &) const;
        bool operator <(const const_iterator &) const;
        bool operator >(const const_iterator &) const;
    };

    Container(unsigned int = 0);
    Container(unsigned int, const T &);

    Container(const Container &);
    Container & operator =(const Container &);
    ~Container();

    T & operator [](unsigned int);
    const T & operator [](unsigned int) const;

    bool operator ==(const Container &) const;
    bool operator !=(const Container &) const;
    bool operator <=(const Container &) const;
    bool operator >=(const Container &) const;
    bool operator <(const Container &) const;
    bool operator >(const Container &) const;

    unsigned int size() const;
    unsigned int capacity() const;
    unsigned int max_size() const;

    bool empty() const;
    void clear();

    void push_back(const T &);
    void pop_back();

    T & front();
    T & back();
    const T & front() const;
    const T & back() const;

    iterator insert(iterator, const T &);
    void insert(iterator, int, const T &);

    iterator erase(iterator);
    iterator erase(iterator, iterator);

    iterator search(const T &);
    const_iterator search(const T &) const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
};

#endif // CONTAINER_H

// class iterator
template <class T>
Container<T>::iterator::iterator(T * pointer) : pointer(pointer) {}

template <class T>
T & Container<T>::iterator::operator *() const {
    return *pointer;
}

template <class T>
T & Container<T>::iterator::operator [](int index) const {
    return *(pointer + index);
}

template <class T>
T * Container<T>::iterator::operator ->() const {
    return pointer;
}

template <class T>
typename Container<T>::iterator & Container<T>::iterator::operator ++() {
    ++pointer;
    return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator ++(int) {
    iterator it(*this);
    ++pointer;
    return it;
}

template <class T>
typename Container<T>::iterator & Container<T>::iterator::operator --() {
    --pointer;
    return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator --(int) {
    iterator it(*this);
    --pointer;
    return it;
}

template <class T>
typename Container<T>::iterator & Container<T>::iterator::operator +=(int positions) {
    pointer += positions;
    return *this;
}

template <class T>
typename Container<T>::iterator & Container<T>::iterator::operator -=(int positions) {
    pointer -= positions;
    return *this;
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator +(int positions) const {
    return itarator(pointer + positions);
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator -(int positions) const {
    return iterator(pointer - positions);
}

template <class T>
bool Container<T>::iterator::operator ==(const const_iterator & c_it) const {
    return pointer == c_it.pointer;
}

template <class T>
bool Container<T>::iterator::operator !=(const const_iterator & c_it) const {
    return pointer != c_it.pointer;
}

template <class T>
bool Container<T>::iterator::operator <=(const const_iterator & c_it) const {
    return pointer <= c_it.pointer;
}

template <class T>
bool Container<T>::iterator::operator >=(const const_iterator & c_it) const {
    return pointer >= c_it.pointer;
}

template <class T>
bool Container<T>::iterator::operator <(const const_iterator & c_it) const {
    return pointer < c_it.pointer;
}

template <class T>
bool Container<T>::iterator::operator >(const const_iterator & c_it) const {
    return pointer > c_it.pointer;
}

// class const_iterator
template <class T>
Container<T>::const_iterator::const_iterator(const T * pointer) : pointer(pointer) {}

template <class T>
Container<T>::const_iterator::const_iterator(const iterator & it) : pointer(it.pointer) {}

template <class T>
const T & Container<T>::const_iterator::operator *() const {
    return *pointer;
}

template <class T>
const T & Container<T>::const_iterator::operator [](int index) const {
    return *(pointer + index);
}

template <class T>
const T * Container<T>::const_iterator::operator ->() const {
    return pointer;
}

template <class T>
typename Container<T>::const_iterator & Container<T>::const_iterator::operator ++() {
    ++pointer;
    return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator ++(int) {
    const_iterator c_it(*this);
    ++pointer;
    return c_it;
}

template <class T>
typename Container<T>::const_iterator & Container<T>::const_iterator::operator --() {
    --pointer;
    return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator --(int) {
    const_iterator c_it(*this);
    --pointer;
    return c_it;
}

template <class T>
typename Container<T>::const_iterator & Container<T>::const_iterator::operator +=(int positions) {
    pointer += positions;
    return *this;
}

template <class T>
typename Container<T>::const_iterator & Container<T>::const_iterator::operator -=(int positions) {
    pointer -= positions;
    return *this;
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator +(int positions) const {
    return const_iterator(pointer + positions);
}

template <class T>
typename Container<T>::const_iterator Container<T>::const_iterator::operator -(int positions) const {
    return const_iterator(pointer - positions);
}

template <class T>
bool Container<T>::const_iterator::operator ==(const const_iterator & c_it) const {
    return pointer == c_it.pointer;
}

template <class T>
bool Container<T>::const_iterator::operator !=(const const_iterator & c_it) const {
    return pointer != c_it.pointer;
}

template <class T>
bool Container<T>::const_iterator::operator <=(const const_iterator & c_it) const {
    return pointer <= c_it.pointer;
}

template <class T>
bool Container<T>::const_iterator::operator >=(const const_iterator & c_it) const {
    return pointer >= c_it.pointer;
}

template <class T>
bool Container<T>::const_iterator::operator <(const const_iterator & c_it) const {
    return pointer < c_it.pointer;
}

template <class T>
bool Container<T>::const_iterator::operator >(const const_iterator & c_it) const {
    return pointer > c_it.pointer;
}

// class Container
template <class T>
T * Container<T>::copy(T * vector, unsigned int size, unsigned int copy_size) {
    T * new_vector = size ? new T[copy_size] : nullptr;
    for (int index = 0; (index < size) && (index < copy_size); ++index) {
        new_vector[index] = vector[index];
    }
    return new_vector;
}

template <class T>
Container<T>::Container(unsigned int) {}

template <class T>
Container<T>::Container(unsigned int, const T &) {}

template <class T>
Container<T>::Container(const Container &)  {

}

template <class T>
Container<T> & Container<T>::operator =(const Container &) {

}

template <class T>
Container<T>::~Container() {

}

template <class T>
T & Container<T>::operator [](unsigned int) {

}

template <class T>
const T & Container<T>::operator [](unsigned int) const {

}

template <class T>
bool Container<T>::operator ==(const Container &) const {

}

template <class T>
bool Container<T>::operator !=(const Container &) const {

}

template <class T>
bool Container<T>::operator <=(const Container &) const {

}

template <class T>
bool Container<T>::operator >=(const Container &) const {

}

template <class T>
bool Container<T>::operator <(const Container &) const {

}

template <class T>
bool Container<T>::operator >(const Container &) const {

}

template <class T>
unsigned int Container<T>::size() const {

}

template <class T>
unsigned int Container<T>::capacity() const {

}

template <class T>
unsigned int Container<T>::max_size() const {

}

template <class T>
bool Container<T>::empty() const {

}

template <class T>
void Container<T>::clear() {

}

template <class T>
void Container<T>::push_back(const T &) {

}

template <class T>
void Container<T>::pop_back() {

}

template <class T>
T & Container<T>::front() {

}

template <class T>
T & Container<T>::back() {

}

template <class T>
const T & Container<T>::front() const {

}

template <class T>
const T & Container<T>::back() const {

}

template <class T>
typename Container<T>::iterator Container<T>::insert(iterator, const T &) {

}

template <class T>
void Container<T>::insert(iterator, int, const T &) {

}

template <class T>
typename Container<T>::iterator Container<T>::erase(iterator) {

}

template <class T>
typename Container<T>::iterator Container<T>::erase(iterator, iterator) {

}

template <class T>
typename Container<T>::iterator Container<T>::search(const T &) {

}

template <class T>
typename Container<T>::const_iterator Container<T>::search(const T &) const {

}

template <class T>
typename Container<T>::iterator Container<T>::begin() {

}

template <class T>
typename Container<T>::iterator Container<T>::end() {

}

template <class T>
typename Container<T>::const_iterator Container<T>::begin() const {

}

template <class T>
typename Container<T>::const_iterator Container<T>::end() const {

}

template <class T>
typename Container<T>::const_iterator Container<T>::cbegin() const {

}

template <class T>
typename Container<T>::const_iterator Container<T>::cend() const {

}
