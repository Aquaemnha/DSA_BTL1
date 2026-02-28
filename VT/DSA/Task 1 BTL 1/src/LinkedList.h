#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Cấu trúc Node
struct Node
{
    int data;
    Node *next;

    Node(int value);
};

// Thêm node vào đầu danh sách
void insertHead(Node *&head, int value);

// Đếm số node trong LinkedList
int countNodes(Node *head);

void printList(Node *head);
void freeList(Node *&head);

#endif
