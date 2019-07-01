#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
private:
    T * vector;
    unsigned int vector_size;
    unsigned int vector_capacity;

    static T * copy(T *, unsigned int, unsigned int);
    static void destroy(T *);
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

        int operator -(const const_iterator &) const;

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

        int operator -(const const_iterator &) const;

        bool operator ==(const const_iterator &) const;
        bool operator !=(const const_iterator &) const;
        bool operator <=(const const_iterator &) const;
        bool operator >=(const const_iterator &) const;
        bool operator <(const const_iterator &) const;
        bool operator >(const const_iterator &) const;
    };

    Container(unsigned int = 1);
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

    bool empty() const;
    void clear();

    void push_back(const T &);
    void pop_back();

    T & front();
    T & back();
    const T & front() const;
    const T & back() const;

    iterator insert(iterator, const T &);
    void insert(iterator, unsigned int, const T &);

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
    return iterator(pointer + positions);
}

template <class T>
typename Container<T>::iterator Container<T>::iterator::operator -(int positions) const {
    return iterator(pointer - positions);
}

template<class T>
int Container<T>::iterator::operator -(const const_iterator & c_it) const {
    return pointer - c_it.pointer;
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
int Container<T>::const_iterator::operator -(const const_iterator & c_it) const {
    return pointer - c_it.pointer;
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
    for (unsigned int index = 0; index < size && index < copy_size; ++index)
        new_vector[index] = vector[index];
    return new_vector;
}

template <class T>
void Container<T>::destroy(T * vector) {
    if (vector)
        delete [] vector;
}

template <class T>
Container<T>::Container(unsigned int capacity) : vector(new T[capacity]), vector_size(0), vector_capacity(capacity) {}

template <class T>
Container<T>::Container(unsigned int size, const T & object) : vector(new T[size]), vector_size(size), vector_capacity(size) {
    for (unsigned int index = 0; index < size; ++index)
        vector[index] = object;
}

template <class T>
Container<T>::Container(const Container & container) : vector(copy(container.vector, container.vector_size, container.vector_capacity)), vector_size(container.vector_size), vector_capacity(container.vector_capacity) {}

template <class T>
Container<T> & Container<T>::operator =(const Container & container) {
    if (this != &container) {
        destroy(vector);
        vector = copy(container.vector, container.vector_size, container.vector_capacity);
        vector_size = container.vector_size;
        vector_capacity = container.vector_capacity;
    }
    return *this;
}

template <class T>
Container<T>::~Container() {
    destroy(vector);
}

template <class T>
T & Container<T>::operator [](unsigned int index) {
    return vector[index];
}

template <class T>
const T & Container<T>::operator [](unsigned int index) const {
    return vector[index];
}

template <class T>
bool Container<T>::operator ==(const Container & container) const {
    bool result = vector_size == container.vector_size ? true : false;
    for (unsigned int index = 0; result && index < vector_size; ++index)
        if (vector[index] != container.vector[index])
            result = false;
    return result;
}

template <class T>
bool Container<T>::operator !=(const Container & container) const {
    return !(*this == container);
}

template <class T>
bool Container<T>::operator <=(const Container & container) const {
    return *this < container || *this == container;
}

template <class T>
bool Container<T>::operator >=(const Container & container) const {
    return *this > container || *this == container;
}

template <class T>
bool Container<T>::operator <(const Container & container) const {
    unsigned int minimum_size = vector_size <= container.vector_size ? vector_size : container.vector_size;
    bool stop = false;
    bool result = true;
    for (unsigned int index = 0; index < minimum_size && !stop; ++index)
        if (vector[index] != container.vector[index]) {
            stop = true;
            result = vector[index] < container.vector[index] ? true : false;
        }
    return result && vector_size < container.vector_size ? true : false;
}

template <class T>
bool Container<T>::operator >(const Container & container) const {
    unsigned int minimum_size = vector_size <= container.vector_size ? vector_size : container.vector_size;
    bool stop = false;
    bool result = true;
    for (unsigned int index = 0; index < minimum_size && !stop; ++index)
        if (vector[index] != container.vector[index]) {
            stop = true;
            result = vector[index] > container.vector[index] ? true : false;
        }
    return result && vector_size > container.vector_size ? true : false;
}

template <class T>
unsigned int Container<T>::size() const {
    return vector_size;
}

template <class T>
unsigned int Container<T>::capacity() const {
    return vector_capacity;
}

template <class T>
bool Container<T>::empty() const {
    return !vector_size;
}

template <class T>
void Container<T>::clear() {
    erase(begin(), end());
}

template <class T>
void Container<T>::push_back(const T & object) {
    if (vector_size == vector_capacity) {
        vector_capacity *= 2;
        T * array = copy(vector, vector_size, vector_capacity);
        destroy(vector);
        vector = array;
    }
    vector[vector_size++] = object;
}

template <class T>
void Container<T>::pop_back() {
    if (vector_size)
        --vector_size;
}

template <class T>
T & Container<T>::front() {
    return vector[0];
}

template <class T>
T & Container<T>::back() {
    return vector[vector_size - 1];
}

template <class T>
const T & Container<T>::front() const {
    return vector[0];
}

template <class T>
const T & Container<T>::back() const {
    return vector[vector_size - 1];
}

template <class T>
typename Container<T>::iterator Container<T>::insert(iterator it, const T & object) {
    return insert(it, 1, object);
}

template <class T>
void Container<T>::insert(iterator it, unsigned int elements, const T & object) {
    if (vector_size + elements > vector_capacity) {
        while (vector_capacity < vector_size + elements)
            vector_capacity *= 2;
        T * array = copy(vector, vector_size, vector_capacity);
        destroy(vector);
        vector = array;
    }
    vector_size += elements;
    for (iterator shift_it = end() - 1; shift_it >= it + elements; --shift_it)
        *shift_it = *(shift_it - elements);
    for (; it < it + elements; ++it)
        *it = object;
}

template <class T>
typename Container<T>::iterator Container<T>::erase(iterator it) {
    return erase(it, it + 1);
}

template <class T>
typename Container<T>::iterator Container<T>::erase(iterator first_it, iterator last_it) {
    if (first_it > last_it)
        return erase(last_it, first_it);
    if (first_it < begin())
        return erase(begin(), last_it);
    if (last_it > end())
        return erase(first_it, end());
    iterator it(nullptr);
    if (vector_size) {
        unsigned int erased_elements = first_it - last_it;
        it = first_it;
        while (last_it != end()) {
            *first_it = *last_it;
            ++first_it;
            ++last_it;
        }
        vector_size -= erased_elements;
    }
    return it;
}

template <class T>
typename Container<T>::iterator Container<T>::search(const T & object) {
    iterator it;
    bool found = false;
    for (it = begin(); !found && it != end(); ++it)
        if (*it == object)
            found = true;
    return found ? it : iterator(nullptr);
}

template <class T>
typename Container<T>::const_iterator Container<T>::search(const T & object) const {
    const_iterator c_it;
    bool found = false;
    for (c_it = begin(); !found && c_it != end(); ++c_it)
        if (*c_it == object)
            found = true;
    return found ? c_it : const_iterator(nullptr);
}

template <class T>
typename Container<T>::iterator Container<T>::begin() {
    return iterator(vector);
}

template <class T>
typename Container<T>::iterator Container<T>::end() {
    return iterator(vector + vector_size);
}

template <class T>
typename Container<T>::const_iterator Container<T>::begin() const {
    return const_iterator(vector);
}

template <class T>
typename Container<T>::const_iterator Container<T>::end() const {
    return const_iterator(vector + vector_size);
}

template <class T>
typename Container<T>::const_iterator Container<T>::cbegin() const {
    return const_iterator(vector);
}

template <class T>
typename Container<T>::const_iterator Container<T>::cend() const {
    return const_iterator(vector + vector_size);
}
