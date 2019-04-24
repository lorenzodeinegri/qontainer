#ifndef DEEPPOINTER_H
#define DEEPPOINTER_H

template <class T>
class DeepPointer {
private:
    T * pointer;
public:
    DeepPointer(T * = nullptr);

    DeepPointer(const DeepPointer &);
    DeepPointer & operator =(const DeepPointer &);
    ~DeepPointer();

    T & operator *() const;
    T * operator ->() const;

    bool operator ==(const DeepPointer &) const;
    bool operator !=(const DeepPointer &) const;
};

template<class T>
DeepPointer<T>::DeepPointer(T * ptr) : pointer(ptr) {}

template<class T>
DeepPointer<T>::DeepPointer(const DeepPointer & deepPointer) : pointer(deepPointer.pointer != nullptr ? deepPointer.pointer->clone() : nullptr) {}

template<class T>
DeepPointer<T> & DeepPointer<T>::operator =(const DeepPointer & deepPointer)
{
    if (this != &deepPointer) {
        if (pointer)
            delete pointer;
        pointer = deepPointer.pointer != nullptr ? deepPointer.pointer->clone() : nullptr;
    }
}

template<class T>
DeepPointer<T>::~DeepPointer()
{
    if (pointer)
        delete pointer;
}

template<class T>
T & DeepPointer<T>::operator *() const
{
    return * pointer;
}

template<class T>
T * DeepPointer<T>::operator ->() const
{
    return pointer;
}

template<class T>
bool DeepPointer<T>::operator ==(const DeepPointer<T> & deepPointer) const
{
    return pointer == deepPointer.pointer;
}

template<class T>
bool DeepPointer<T>::operator !=(const DeepPointer<T> & deepPointer) const
{
    return pointer != deepPointer.pointer;
}

#endif // DEEPPOINTER_H
