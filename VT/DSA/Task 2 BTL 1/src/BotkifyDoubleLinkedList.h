#ifndef BOTKIFY_DOUBLE_LINKED_LIST_H
#define BOTKIFY_DOUBLE_LINKED_LIST_H

#include "BotkifyLinkedList.h"

template <class T>
class BotkifyDoubleLinkedList : public BotkifyLinkedList<T>
{
    using Base = BotkifyLinkedList<T>;
    using Node = typename Base::Node;

public:
    BotkifyDoubleLinkedList();
    ~BotkifyDoubleLinkedList();

    void add(T e) override;
    void add(int index, T e) override;
    T removeAt(int index) override;
    bool removeItem(T item) override;
    void clear() override;
    T &get(int index) const override;
    string toString() const override;
};

template <class T>
BotkifyDoubleLinkedList<T>::BotkifyDoubleLinkedList()
{
    // TODO
}

template <class T>
BotkifyDoubleLinkedList<T>::~BotkifyDoubleLinkedList()
{
    // TODO
}

template <class T>
void BotkifyDoubleLinkedList<T>::add(T e)
{
    // TODO
}

template <class T>
void BotkifyDoubleLinkedList<T>::add(int index, T e)
{
    // TODO
}

template <class T>
T BotkifyDoubleLinkedList<T>::removeAt(int index)
{
    // TODO
}

template <class T>
bool BotkifyDoubleLinkedList<T>::removeItem(T item)
{
    // TODO
    return false;
}

template <class T>
void BotkifyDoubleLinkedList<T>::clear()
{
    // TODO
}

template <class T>
T &BotkifyDoubleLinkedList<T>::get(int index) const
{
    // TODO
}

template <class T>
string BotkifyDoubleLinkedList<T>::toString() const
{
    // TODO
    return "";
}

#endif // BOTKIFY_DOUBLE_LINKED_LIST_H
