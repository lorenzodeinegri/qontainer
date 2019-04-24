#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
private:
    T * vector;
    unsigned int vector_size;
    unsigned int vector_capacity;
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
