#ifndef BOTKIFY_LINKED_LIST_H
#define BOTKIFY_LINKED_LIST_H

#include "main.h"

// ===== Abstract Base Class =====
template <class T>
class BotkifyLinkedList
{
protected:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *extra;
        Node() : next(nullptr), extra(nullptr) {}
        Node(const T &data, Node *next = nullptr, Node *extra = nullptr)
            : data(data), next(next), extra(extra) {}
        virtual ~Node() = default;
    };

    Node *head;
    Node *tail;
    int count;

public:
    BotkifyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    virtual ~BotkifyLinkedList() {}

    // --- Pure virtual interface ---
    virtual void add(T e) = 0;
    virtual void add(int index, T e) = 0;
    virtual T removeAt(int index) = 0;
    virtual bool removeItem(T item) = 0;

    virtual bool empty() const { return count == 0; }
    virtual int size() const { return count; }
    virtual void clear() = 0;

    virtual T &get(int index) const = 0;
    virtual string toString() const = 0;
};

#endif // BOTKIFY_LINKED_LIST_H
