#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
private:
    T * vector;
    unsigned int vector_size;
    unsigned int vector_capacity;

    T * copy(unsigned int, unsigned int);
public:
    class iterator;
    class const_iterator;

    class iterator {
    private:
        T * pointer;
        bool past_the_end;

        iterator(T * = nullptr, bool = false);
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
    private:
        const T * pointer;
        bool past_the_end;
        const_iterator(const T * = nullptr, bool = false);
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

template <class T>
Container::iterator::iterator(T * ptr, bool pte) : pointer(ptr), past_the_end(pte) {}

template <class T>
T & Container::iterator::operator *() const {
    return *pointer;
}

template <class T>
T & Container::iterator::operator [](int index) const {
    return *(pointer + index);
}

template <class T>
T * Container::iterator::operator ->() const {
    return pointer;
}

template <class T>
Container::iterator & Container::iterator::operator ++() {
    if ((!past_the_end) (++pointer == (pointer + vector_size)))
        past_the_end = true;
    return *this
}

template <class T>
Container::iterator Container::iterator::operator ++(int) {
    iterator it = *this;
    if ((!past_the_end) && (++pointer == (pointer + vector_size)))
        past_the_end = true;
    return it;
}

template <class T>
Container::iterator & Container::iterator::operator --() {
    if (--pointer == (pointer + vector_size - 1))
        past_the_end = false;
    return *this;
}

template <class T>
Container::iterator Container::iterator::operator --(int) {
    iterator it = *this;
    if (--pointer == (pointer + vector_size - 1))
        past_the_end = false;
    return it;
}

template <class T>
Container::iterator & Container::iterator::operator +=(int number) {

}

template <class T>
Container::iterator & Container::iterator::operator -=(int) {

}

template <class T>
Container::iterator Container::iterator::operator +(int) const {

}

template <class T>
Container::iterator Container::iterator::operator -(int) const {

}

template <class T>
bool Container::iterator::operator ==(const Container::const_iterator &) const {

}

template <class T>
bool Container::iterator::operator !=(const Container::const_iterator &) const {

}

template <class T>
bool Container::iterator::operator <=(const Container::const_iterator &) const {

}

template <class T>
bool Container::iterator::operator >=(const Container::const_iterator &) const {

}

template <class T>
bool Container::iterator::operator <(const Container::const_iterator &) const {

}

template <class T>
bool Container::iterator::operator >(const Container::const_iterator &) const {

}

template <class T>
Container::const_iterator::const_iterator(const T *, bool) {}

template <class T>
Container::const_iterator::const_iterator(const Container::iterator &) {}

template <class T>
const T & Container::const_iterator::operator *() const {

}

template <class T>
const T & Container::const_iterator::operator [](int) const {

}

template <class T>
const T * Container::const_iterator::operator ->() const {

}

template <class T>
Container::const_iterator &Container::const_iterator::operator ++() {

}

template <class T>
Container::const_iterator Container::const_iterator::operator ++(int) {

}

template <class T>
Container::const_iterator &Container::const_iterator::operator --() {

}

template <class T>
Container::const_iterator Container::const_iterator::operator --(int) {

}

template <class T>
Container::const_iterator &Container::const_iterator::operator +=(int) {

}

template <class T>
Container::const_iterator &Container::const_iterator::operator -=(int) {

}

template <class T>
Container::const_iterator Container::const_iterator::operator +(int) const {

}

template <class T>
Container::const_iterator Container::const_iterator::operator -(int) const {

}

template <class T>
bool Container::const_iterator::operator ==(const Container::const_iterator &) const {

}

template <class T>
bool Container::const_iterator::operator !=(const Container::const_iterator &) const {

}

template <class T>
bool Container::const_iterator::operator <=(const Container::const_iterator &) const {

}

template <class T>
bool Container::const_iterator::operator >=(const Container::const_iterator &) const {

}

template <class T>
bool Container::const_iterator::operator <(const Container::const_iterator &) const {

}

template <class T>
bool Container::const_iterator::operator >(const Container::const_iterator &) const {

}

template <class T>
T *Container::copy(unsigned int, unsigned int) {

}

template <class T>
Container::Container(unsigned int) {}

template <class T>
Container::Container(unsigned int, const T &) {}

template <class T>
Container::Container(const Container &)  {

}

template <class T>
Container &Container::operator =(const Container &) {

}

template <class T>
Container::~Container() {

}

template <class T>
T &Container::operator [](unsigned int) {

}

template <class T>
const T &Container::operator [](unsigned int) const {

}

template <class T>
bool Container::operator ==(const Container &) const {

}

template <class T>
bool Container::operator !=(const Container &) const {

}

template <class T>
bool Container::operator <=(const Container &) const {

}

template <class T>
bool Container::operator >=(const Container &) const {

}

template <class T>
bool Container::operator <(const Container &) const {

}

template <class T>
bool Container::operator >(const Container &) const {

}

template <class T>
unsigned int Container::size() const {

}

template <class T>
unsigned int Container::capacity() const {

}

template <class T>
unsigned int Container::max_size() const {

}

template <class T>
bool Container::empty() const {

}

template <class T>
void Container::clear() {

}

template <class T>
void Container::push_back(const T &) {

}

template <class T>
void Container::pop_back() {

}

template <class T>
T & Container::front() {

}

template <class T>
T & Container::back() {

}

template <class T>
const T & Container::front() const {

}

template <class T>
const T & Container::back() const {

}

template <class T>
Container::iterator Container::insert(Container::iterator, const T &) {

}

template <class T>
void Container::insert(Container::iterator, int, const T &) {

}

template <class T>
Container::iterator Container::erase(Container::iterator) {

}

template <class T>
Container::iterator Container::erase(Container::iterator, Container::iterator) {

}

template <class T>
Container::iterator Container::search(const T &) {

}

template <class T>
Container::const_iterator Container::search(const T &) const {

}

template <class T>
Container::iterator Container::begin() {

}

template <class T>
Container::iterator Container::end() {

}

template <class T>
Container::const_iterator Container::begin() const {

}

template <class T>
Container::const_iterator Container::end() const {

}

template <class T>
Container::const_iterator Container::cbegin() const {

}

template <class T>
Container::const_iterator Container::cend() const {

}
