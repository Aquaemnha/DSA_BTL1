#include "LinkedList.h"

// Constructor cho Node
Node::Node(int value)
{
    data = value;
    next = nullptr;
}

void insertHead(Node *&head, int value)
{
    // TODO Thêm node vào đầu LinkedList
}

int countNodes(Node *head)
{
    // TODO Đếm số node trong LinkedList
    return 0;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void freeList(Node *&head)
{
    while (head != nullptr)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}