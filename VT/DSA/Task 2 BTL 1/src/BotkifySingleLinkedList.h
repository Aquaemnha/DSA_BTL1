#ifndef BOTKIFY_SINGLE_LINKED_LIST_H
#define BOTKIFY_SINGLE_LINKED_LIST_H

#include "BotkifyLinkedList.h"

template <class T>
class BotkifySingleLinkedList : public BotkifyLinkedList<T>
{
    using Base = BotkifyLinkedList<T>;
    using Node = typename Base::Node;

public:
    BotkifySingleLinkedList();
    ~BotkifySingleLinkedList();

    void add(T e) override;
    void add(int index, T e) override;
    T removeAt(int index) override;
    bool removeItem(T item) override;
    void clear() override;
    T &get(int index) const override;
    string toString() const override;
};

template <class T>
BotkifySingleLinkedList<T>::BotkifySingleLinkedList()
{
    // TODO
}

template <class T>
BotkifySingleLinkedList<T>::~BotkifySingleLinkedList()
{
    // TODO
}

template <class T>
void BotkifySingleLinkedList<T>::add(T e)
{
    // TODO
}

template <class T>
void BotkifySingleLinkedList<T>::add(int index, T e)
{
    // TODO
}

template <class T>
T BotkifySingleLinkedList<T>::removeAt(int index)
{
    // TODO
}

template <class T>
bool BotkifySingleLinkedList<T>::removeItem(T item)
{
    // TODO
    return false;
}

template <class T>
void BotkifySingleLinkedList<T>::clear()
{
    // TODO
}

template <class T>
T &BotkifySingleLinkedList<T>::get(int index) const
{
    // TODO
}

template <class T>
string BotkifySingleLinkedList<T>::toString() const
{
    // TODO
    return "";
}

#endif // BOTKIFY_SINGLE_LINKED_LIST_H
