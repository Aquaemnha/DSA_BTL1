#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

template <class T>
class BotkifyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node* next;
        Node* extra;

        Node();
        Node(const T& data, Node* next = nullptr, Node* extra = nullptr);
    };

    Node* head;
    Node* tail;
    int count;

public:
    BotkifyLinkedList();
    ~BotkifyLinkedList();

    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item);

    bool empty() const;
    int size() const;
    void clear();

    T& get(int index) const;

    string toString() const;
};

template<class T>
BotkifyLinkedList<T>::Node::Node() : next(nullptr), extra(nullptr) {}

// TODO CODE


#endif // BOTKIFY_LINKED_LIST_H
