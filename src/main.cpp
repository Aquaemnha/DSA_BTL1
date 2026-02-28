#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

// ============================================================================
// INCLUDE CÁC FILE HEADER TRONG BÀI LÀM HIỆN TẠI
// ============================================================================
#include "BotkifyLinkedList.h"
#include "Playlist.h"

// ============================================================================
// HỆ THỐNG CUSTOM ASSERT TƯƠNG ĐƯƠNG DOCTEST
// ============================================================================
int passed = 0;
int failed = 0;

#define CHECK(cond) \
    do { \
        if (!(cond)) { \
            std::cout << "  [FAILED] " << #cond << " at line " << __LINE__ << "\n"; \
            failed++; \
        } else { \
            passed++; \
        } \
    } while(0)

#define REQUIRE(cond) \
    do { \
        if (!(cond)) { \
            std::cout << "  [FAILED - FATAL] " << #cond << " at line " << __LINE__ << "\n"; \
            failed++; \
            return; \
        } else { \
            passed++; \
        } \
    } while(0)

#define REQUIRE_THROWS_AS(expr, type) \
    do { \
        bool threw = false; \
        try { expr; } \
        catch (const type&) { threw = true; } \
        catch (...) {} \
        if (!threw) { \
            std::cout << "  [FAILED] Expected exception " << #type << " from " << #expr << " at line " << __LINE__ << "\n"; \
            failed++; \
        } else { \
            passed++; \
        } \
    } while(0)

#define REQUIRE_THROWS_WITH(expr, msg) \
    do { \
        bool threw = false; \
        try { expr; } \
        catch (const std::exception& e) { \
            threw = true; \
            if (std::string(e.what()) != msg) { \
                std::cout << "  [FAILED] Exception message mismatch: expected \"" << msg << "\", got \"" << e.what() << "\" at line " << __LINE__ << "\n"; \
                failed++; \
            } else { \
                passed++; \
            } \
        } \
        catch (...) {} \
        if (!threw) { \
            std::cout << "  [FAILED] Expected exception with message \"" << msg << "\" at line " << __LINE__ << "\n"; \
            failed++; \
        } \
    } while(0)

// ============================================================================
// TEST CASES CHÍNH: BotkifyLinkedList
// ============================================================================
void BotkifyLinkedList_001() {
    BotkifyLinkedList<int> list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
    list.add(10); list.add(20); list.add(30);
    REQUIRE(list.empty() == false);
    REQUIRE(list.size() == 3);
    REQUIRE(list.toString() == "10,20,30");
}

void BotkifyLinkedList_002() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(30);
    list.add(1,20); list.add(0,5); list.add(4,40); 
    REQUIRE(list.size() == 5);
    REQUIRE(list.toString() == "5,10,20,30,40");
}

void BotkifyLinkedList_003() {
    BotkifyLinkedList<std::string> list;
    list.add("Alice"); list.add("Bob"); list.add("Charlie");
    REQUIRE(list.get(0) == "Alice");
    REQUIRE(list.get(1) == "Bob");
    REQUIRE(list.get(2) == "Charlie");
}

void BotkifyLinkedList_004() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30); list.add(40);
    int removed = list.removeAt(1); 
    REQUIRE(removed == 20); REQUIRE(list.size() == 3); REQUIRE(list.toString() == "10,30,40");
    removed = list.removeAt(0); 
    REQUIRE(removed == 10); REQUIRE(list.toString() == "30,40");
    removed = list.removeAt(1); 
    REQUIRE(removed == 40); REQUIRE(list.toString() == "30");
}

void BotkifyLinkedList_005() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30); list.add(20);
    bool ok = list.removeItem(20); 
    REQUIRE(ok == true); REQUIRE(list.size() == 3); REQUIRE(list.toString() == "10,30,20");
    ok = list.removeItem(100); 
    REQUIRE(ok == false); REQUIRE(list.size() == 3);
    list.clear();
    REQUIRE(list.empty() == true); REQUIRE(list.size() == 0); REQUIRE(list.toString() == "");
}

void BotkifyLinkedList_006() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30);
    REQUIRE_THROWS_AS(list.get(-1),std::out_of_range);
    REQUIRE_THROWS_WITH(list.get(-1),"Index is invalid!");
    REQUIRE_THROWS_AS(list.get(3),std::out_of_range);
    REQUIRE_THROWS_WITH(list.get(3),"Index is invalid!");
}

// ============================================================================
// TEST CASES CHÍNH: Playlist
// ============================================================================
void Playlist_001() {
    Song s(1, "BabyShark", "Pinkfong", "KidsHits", 120, 900, "url");
    CHECK(s.getID() == 1); CHECK(s.getDuration() == 120); CHECK(s.getScore() == 900); CHECK(s.toString() == "BabyShark-Pinkfong");
}

void Playlist_002() {
    Playlist pl("MyList");
    // Dùng getSize() theo class của bạn
    CHECK(pl.empty() == true); CHECK(pl.getSize() == 0);
    Song* s1 = new Song(1,"A","AA","ALB",100,10,"u");
    Song* s2 = new Song(2,"B","BB","ALB",200,20,"u");
    Song* s3 = new Song(3,"C","CC","ALB",300,30,"u");
    
    pl.addSong(s1); CHECK(pl.empty() == false); CHECK(pl.getSize() == 1);
    pl.addSong(s2); pl.addSong(s3); CHECK(pl.getSize() == 3);
    
    pl.removeSong(1); 
    CHECK(pl.getSize() == 2); CHECK(pl.getSong(0)->getID() == 1); CHECK(pl.getSong(1)->getID() == 3);
    REQUIRE_THROWS_AS(pl.removeSong(5),std::out_of_range); REQUIRE_THROWS_WITH(pl.removeSong(5),"Index is invalid!");
    
    pl.clear(); CHECK(pl.getSize() == 0); CHECK(pl.empty() == true);
    delete s1; delete s2; delete s3;
}

void Playlist_003() {
    Playlist pl("PlayTest");
    Song* s1 = new Song(1,"A","AA","ALB",100,10,"u"); pl.addSong(s1);
    CHECK(pl.playNext()->getID() == 1); CHECK(pl.playNext()->getID() == 1); CHECK(pl.playPrevious()->getID() == 1);
    Song* s2 = new Song(2,"B","BB","ALB",200,20,"u"); Song* s3 = new Song(3,"C","CC","ALB",300,30,"u");
    pl.addSong(s2); pl.addSong(s3);
    CHECK(pl.playNext()->getID() == 2); CHECK(pl.playNext()->getID() == 3); CHECK(pl.playNext()->getID() == 1); 
    CHECK(pl.playPrevious()->getID() == 3); CHECK(pl.playPrevious()->getID() == 2); CHECK(pl.playPrevious()->getID() == 1); 
    delete s1; delete s2; delete s3;
}

void Playlist_004() {
    Playlist pl("ScoreTest");
    Song* s1 = new Song(1,"A","a","",0,4,""); Song* s2 = new Song(2,"B","b","",0,1,"");
    Song* s3 = new Song(3,"C","c","",0,3,""); Song* s4 = new Song(4,"D","d","",0,5,"");
    pl.addSong(s1); pl.addSong(s2); pl.addSong(s3); pl.addSong(s4);
    CHECK(pl.getTotalScore() == 114);
    delete s1; delete s2; delete s3; delete s4;
}

void Playlist_005() {
    Playlist A("A"); Playlist B("B");
    Song a1(1,"s1","a","al",200,4,"u"); Song a2(2,"s2","a","al",200,1,"u");
    Song a3(3,"s3","a","al",200,3,"u"); Song a4(4,"s4","a","al",200,5,"u");
    Song b1(5,"t1","b","al",200,1,"u"); Song b2(6,"t2","b","al",200,2,"u"); Song b3(7,"t3","b","al",200,3,"u");
    A.addSong(&a1); A.addSong(&a2); A.addSong(&a3); A.addSong(&a4);
    B.addSong(&b1); B.addSong(&b2); B.addSong(&b3);
    CHECK(A.compareTo(B, 2) == true); CHECK(B.compareTo(A, 2) == false);
}

void Playlist_006() {
    Playlist pl("Test");
    Song s1(1,"S1","A","X",50,10,"u"); Song s2(2,"S2","A","X",80,10,"u");
    Song s3(3,"S3","A","X",60,10,"u"); Song s4(4,"S4","A","X",120,10,"u");
    Song s5(5,"S5","A","X",90,10,"u");
    pl.addSong(&s1); pl.addSong(&s2); pl.addSong(&s3); pl.addSong(&s4); pl.addSong(&s5);
    std::ostringstream out; std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());
    pl.playRandom(2); std::cout.rdbuf(oldCout);
    CHECK(out.str() == "S3-A,S4-A");
}

void Playlist_007() {
    Playlist pl("Test");
    Song s1(1,"S1","A","X",50,10,"u"); Song s2(2,"S2","A","X",60,10,"u");
    Song s3(3,"S3","A","X",30,10,"u"); Song s4(4,"S4","A","X",90,10,"u");
    Song s5(5,"S5","A","X",100,10,"u");
    pl.addSong(&s1); pl.addSong(&s2); pl.addSong(&s3); pl.addSong(&s4); pl.addSong(&s5);
    CHECK(pl.playApproximate(1) == 50);
}

// ============================================================================
// CÁC TEST CASE CHUYỂN ĐỔI (Đã ép chạy bằng class BotkifyLinkedList)
// ============================================================================

// --- Từ test_countNodes.cpp ---
void ExtraTest_countNodes_001() {
    BotkifyLinkedList<int> list;
    CHECK(list.size() == 0);
}

void ExtraTest_countNodes_002() {
    BotkifyLinkedList<int> list;
    list.add(0, 5); list.add(0, 10); list.add(0, 15); list.add(0, 20);
    CHECK(list.size() == 4);
}

// --- Từ test_insertHead.cpp ---
void ExtraTest_insertHead_001() {
    BotkifyLinkedList<int> list;
    list.add(0, 10);
    REQUIRE(list.size() == 1); CHECK(list.get(0) == 10);
}

void ExtraTest_insertHead_002() {
    BotkifyLinkedList<int> list;
    list.add(0, 10); list.add(0, 20); list.add(0, 30); 
    REQUIRE(list.size() == 3);
    CHECK(list.get(0) == 30); CHECK(list.get(1) == 20); CHECK(list.get(2) == 10);
    CHECK(list.toString() == "30,20,10"); 
}

// --- Từ test_BotkifySingleLinkedList.cpp ---
void Adapt_Single_001() {
    BotkifyLinkedList<int> list;
    REQUIRE(list.empty() == true); REQUIRE(list.size() == 0);
    list.add(10); list.add(20); list.add(30);
    REQUIRE(list.empty() == false); REQUIRE(list.size() == 3);
    REQUIRE(list.toString() == "10,20,30"); 
}

void Adapt_Single_002() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(30); list.add(1, 20); list.add(0, 5); list.add(4, 40);
    REQUIRE(list.size() == 5); REQUIRE(list.toString() == "5,10,20,30,40");
}

void Adapt_Single_003() {
    BotkifyLinkedList<std::string> list;
    list.add("Alice"); list.add("Bob"); list.add("Charlie");
    REQUIRE(list.get(0) == "Alice"); REQUIRE(list.get(1) == "Bob"); REQUIRE(list.get(2) == "Charlie");
}

void Adapt_Single_004() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30); list.add(40);
    int removed = list.removeAt(1); 
    REQUIRE(removed == 20); REQUIRE(list.size() == 3); REQUIRE(list.toString() == "10,30,40");
    removed = list.removeAt(0); 
    REQUIRE(removed == 10); REQUIRE(list.toString() == "30,40");
    removed = list.removeAt(1); 
    REQUIRE(removed == 40); REQUIRE(list.toString() == "30");
}

void Adapt_Single_005() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30); list.add(20);
    bool ok = list.removeItem(20); 
    REQUIRE(ok == true); REQUIRE(list.size() == 3); REQUIRE(list.toString() == "10,30,20");
    ok = list.removeItem(100); 
    REQUIRE(ok == false); REQUIRE(list.size() == 3);
    list.clear();
    REQUIRE(list.empty() == true); REQUIRE(list.size() == 0); REQUIRE(list.toString() == "");
}

void Adapt_Single_006() {
    BotkifyLinkedList<int> list;
    list.add(10); list.add(20); list.add(30);
    REQUIRE_THROWS_AS(list.get(-1), std::out_of_range); REQUIRE_THROWS_WITH(list.get(-1), "Index is invalid!");
    REQUIRE_THROWS_AS(list.get(3), std::out_of_range); REQUIRE_THROWS_WITH(list.get(3), "Index is invalid!");
}

// --- Từ test_BotkifyDoubleLinkedList.cpp ---
void Adapt_Double_001() { Adapt_Single_001(); } 
void Adapt_Double_002() { Adapt_Single_002(); }
void Adapt_Double_003() { Adapt_Single_003(); }
void Adapt_Double_004() { Adapt_Single_004(); }
void Adapt_Double_005() { Adapt_Single_005(); }
void Adapt_Double_006() { Adapt_Single_006(); }

// --- Từ test_BotkifyCycleDoubleLinkedList.cpp ---
void Adapt_Cycle_001() { Adapt_Single_001(); } 
void Adapt_Cycle_002() { Adapt_Single_002(); }
void Adapt_Cycle_003() { Adapt_Single_003(); }
void Adapt_Cycle_004() { Adapt_Single_004(); }
void Adapt_Cycle_005() { Adapt_Single_005(); }
void Adapt_Cycle_006() { Adapt_Single_006(); }


// ============================================================================
// HÀM MAIN CHÍNH
// ============================================================================
int main() {
    std::cout << "==========================================\n";
    std::cout << "        BẮT ĐẦU CHẠY TẤT CẢ TEST CASES    \n";
    std::cout << "==========================================\n\n";

    std::cout << "--- TEST: BotkifyLinkedList (Goc) ---\n";
    BotkifyLinkedList_001(); BotkifyLinkedList_002(); BotkifyLinkedList_003();
    BotkifyLinkedList_004(); BotkifyLinkedList_005(); BotkifyLinkedList_006();

    std::cout << "\n--- TEST: Playlist ---\n";
    Playlist_001(); Playlist_002(); Playlist_003(); Playlist_004();
    Playlist_005(); Playlist_006(); Playlist_007();

    std::cout << "\n--- TEST: countNodes & insertHead (Adapted) ---\n";
    ExtraTest_countNodes_001(); ExtraTest_countNodes_002();
    ExtraTest_insertHead_001(); ExtraTest_insertHead_002();

    std::cout << "\n--- TEST: BotkifySingleLinkedList (Adapted) ---\n";
    Adapt_Single_001(); Adapt_Single_002(); Adapt_Single_003(); 
    Adapt_Single_004(); Adapt_Single_005(); Adapt_Single_006();

    std::cout << "\n--- TEST: BotkifyDoubleLinkedList (Adapted) ---\n";
    Adapt_Double_001(); Adapt_Double_002(); Adapt_Double_003();
    Adapt_Double_004(); Adapt_Double_005(); Adapt_Double_006();

    std::cout << "\n--- TEST: BotkifyCycleDoubleLinkedList (Adapted) ---\n";
    Adapt_Cycle_001(); Adapt_Cycle_002(); Adapt_Cycle_003();
    Adapt_Cycle_004(); Adapt_Cycle_005(); Adapt_Cycle_006();

    std::cout << "\n==========================================\n";
    std::cout << "TONG KET:\n";
    std::cout << " Passed: " << passed << " conditions\n";
    std::cout << " Failed: " << failed << " conditions\n";
    std::cout << "==========================================\n";

    return (failed == 0) ? 0 : 1;
}