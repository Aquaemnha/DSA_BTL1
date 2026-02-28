#include "doctest.h"
#include "src/LinkedList.h"

TEST_CASE("insertHead_001")
{
    Node *head = nullptr;

    insertHead(head, 10);

    REQUIRE(head != nullptr);
    CHECK(head->data == 10);
    CHECK(head->next == nullptr);

    freeList(head);
}

TEST_CASE("insertHead_002")
{
    Node *head = nullptr;

    insertHead(head, 10); // list: 10
    insertHead(head, 20); // list: 20 -> 10
    insertHead(head, 30); // list: 30 -> 20 -> 10

    REQUIRE(head != nullptr);
    CHECK(head->data == 30);
    REQUIRE(head->next != nullptr);
    CHECK(head->next->data == 20);
    REQUIRE(head->next->next != nullptr);
    CHECK(head->next->next->data == 10);
    CHECK(head->next->next->next == nullptr);

    freeList(head);
}