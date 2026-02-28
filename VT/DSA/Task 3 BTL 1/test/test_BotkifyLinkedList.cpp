#include "doctest.h"
#include "src/BotkifyLinkedList.h"


TEST_CASE("BotkifyLinkedList_001")
{
    BotkifyLinkedList<int> list;

    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);

    list.add(10);
    list.add(20);
    list.add(30);

    REQUIRE(list.empty() == false);
    REQUIRE(list.size() == 3);
    REQUIRE(list.toString() == "10,20,30");
}

TEST_CASE("BotkifyLinkedList_002")
{
    BotkifyLinkedList<int> list;

    list.add(10);
    list.add(30);
    list.add(1,20); // insert in middle
    list.add(0,5);  // insert at head
    list.add(4,40); // insert at tail

    REQUIRE(list.size() == 5);
    REQUIRE(list.toString() == "5,10,20,30,40");
}

TEST_CASE("BotkifyLinkedList_003")
{
    BotkifyLinkedList<string> list;

    list.add("Alice");
    list.add("Bob");
    list.add("Charlie");

    REQUIRE(list.get(0) == "Alice");
    REQUIRE(list.get(1) == "Bob");
    REQUIRE(list.get(2) == "Charlie");
}

TEST_CASE("BotkifyLinkedList_004")
{
    BotkifyLinkedList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    int removed = list.removeAt(1); // remove 20

    REQUIRE(removed == 20);
    REQUIRE(list.size() == 3);
    REQUIRE(list.toString() == "10,30,40");

    removed = list.removeAt(0); // remove 10
    REQUIRE(removed == 10);
    REQUIRE(list.toString() == "30,40");

    removed = list.removeAt(1); // remove 40
    REQUIRE(removed == 40);
    REQUIRE(list.toString() == "30");
}

TEST_CASE("BotkifyLinkedList_005")
{
    BotkifyLinkedList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(20);

    bool ok = list.removeItem(20); // remove first 20

    REQUIRE(ok == true);
    REQUIRE(list.size() == 3);
    REQUIRE(list.toString() == "10,30,20");

    ok = list.removeItem(100); // not found
    REQUIRE(ok == false);
    REQUIRE(list.size() == 3);

    list.clear();
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
    REQUIRE(list.toString() == "");
}

TEST_CASE("BotkifyLinkedList_006")
{
    BotkifyLinkedList<int> list;

    list.add(10);
    list.add(20);
    list.add(30);

    REQUIRE_THROWS_AS(list.get(-1),std::out_of_range);
    REQUIRE_THROWS_WITH(list.get(-1),"Index is invalid!");

    REQUIRE_THROWS_AS(list.get(3),std::out_of_range);
    REQUIRE_THROWS_WITH(list.get(3),"Index is invalid!");
}
