#ifndef BOTKIFY_CYCLE_DOUBLE_LINKED_LIST_H
#define BOTKIFY_CYCLE_DOUBLE_LINKED_LIST_H

#include "BotkifyLinkedList.h"

template <class T>
class BotkifyCycleDoubleLinkedList : public BotkifyLinkedList<T>
{
    using Base = BotkifyLinkedList<T>;
    using Node = typename Base::Node;

public:
    BotkifyCycleDoubleLinkedList();
    ~BotkifyCycleDoubleLinkedList();

    void add(T e) override;
    void add(int index, T e) override;
    T removeAt(int index) override;
    bool removeItem(T item) override;
    void clear() override;
    T &get(int index) const override;
    string toString() const override;
};

template <class T>
BotkifyCycleDoubleLinkedList<T>::BotkifyCycleDoubleLinkedList()
{
    // TODO
}

template <class T>
BotkifyCycleDoubleLinkedList<T>::~BotkifyCycleDoubleLinkedList()
{
    // TODO
}

template <class T>
void BotkifyCycleDoubleLinkedList<T>::add(T e)
{
    // TODO
}

template <class T>
void BotkifyCycleDoubleLinkedList<T>::add(int index, T e)
{
    // TODO
}

template <class T>
T BotkifyCycleDoubleLinkedList<T>::removeAt(int index)
{
    // TODO
}

template <class T>
bool BotkifyCycleDoubleLinkedList<T>::removeItem(T item)
{
    // TODO
    return false;
}

template <class T>
void BotkifyCycleDoubleLinkedList<T>::clear()
{
    // TODO
}

template <class T>
T &BotkifyCycleDoubleLinkedList<T>::get(int index) const
{
    // TODO
}

template <class T>
string BotkifyCycleDoubleLinkedList<T>::toString() const
{
    // TODO
    return "";
}

#endif // BOTKIFY_CYCLE_DOUBLE_LINKED_LIST_H
