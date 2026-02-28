#include "doctest.h"
#include "src/LinkedList.h"

TEST_CASE("countNodes_001")
{
    Node *head = nullptr;

    CHECK(countNodes(head) == 0);
}

TEST_CASE("countNodes_002")
{
    Node *head = nullptr;

    insertHead(head, 5);
    insertHead(head, 10);
    insertHead(head, 15);
    insertHead(head, 20);

    CHECK(countNodes(head) == 4);

    freeList(head);
}
