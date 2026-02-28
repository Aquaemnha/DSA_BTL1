#include "doctest.h"
#include "src/Playlist.h"


TEST_CASE("Playlist_001")
{
    Song s(1, "BabyShark", "Pinkfong", "KidsHits", 120, 900, "url");

    CHECK(s.getID() == 1);
    CHECK(s.getDuration() == 120);
    CHECK(s.getScore() == 900);
    CHECK(s.toString() == "BabyShark-Pinkfong");
}


TEST_CASE("Playlist_002")
{
    Playlist pl("MyList");

    // Constructor
    CHECK(pl.empty() == true);
    CHECK(pl.size() == 0);

    // AddSong
    Song* s1 = new Song(1,"A","AA","ALB",100,10,"u");
    Song* s2 = new Song(2,"B","BB","ALB",200,20,"u");
    Song* s3 = new Song(3,"C","CC","ALB",300,30,"u");

    pl.addSong(s1);
    CHECK(pl.empty() == false);
    CHECK(pl.size() == 1);

    pl.addSong(s2);
    pl.addSong(s3);
    CHECK(pl.size() == 3);

    // RemoveSong valid
    pl.removeSong(1); // remove s2
    CHECK(pl.size() == 2);
    CHECK(pl.getSong(0)->getID() == 1);
    CHECK(pl.getSong(1)->getID() == 3);

    // RemoveSong invalid
    REQUIRE_THROWS_AS(pl.removeSong(5),std::out_of_range);
    REQUIRE_THROWS_WITH(pl.removeSong(5),"Index is invalid!");

    // Clear
    pl.clear();
    CHECK(pl.size() == 0);
    CHECK(pl.empty() == true);

    delete s1;
    delete s2;
    delete s3;
}


TEST_CASE("Playlist_003")
{
    Playlist pl("PlayTest");

    // 1 bài hát
    Song* s1 = new Song(1,"A","AA","ALB",100,10,"u");
    pl.addSong(s1);

    CHECK(pl.playNext()->getID() == 1);
    CHECK(pl.playNext()->getID() == 1);
    CHECK(pl.playPrevious()->getID() == 1);

    // Thêm thêm bài
    Song* s2 = new Song(2,"B","BB","ALB",200,20,"u");
    Song* s3 = new Song(3,"C","CC","ALB",300,30,"u");

    pl.addSong(s2);
    pl.addSong(s3);
    // Playlist: [1,2,3]
    // currentIndex đang ở 0 (s1)

    // Next
    CHECK(pl.playNext()->getID() == 2); // 1 -> 2
    CHECK(pl.playNext()->getID() == 3); // 2 -> 3
    CHECK(pl.playNext()->getID() == 1); // 3 -> quay lại 1

    // Previous
    CHECK(pl.playPrevious()->getID() == 3); // 1 -> 3
    CHECK(pl.playPrevious()->getID() == 2); // 3 -> 2
    CHECK(pl.playPrevious()->getID() == 1); // 2 -> 1

    delete s1;
    delete s2;
    delete s3;
}

TEST_CASE("Playlist_004")
{
    Playlist pl("ScoreTest");

    Song* s1 = new Song(1,"A","a","",0,4,"");
    Song* s2 = new Song(2,"B","b","",0,1,"");
    Song* s3 = new Song(3,"C","c","",0,3,"");
    Song* s4 = new Song(4,"D","d","",0,5,"");

    pl.addSong(s1);
    pl.addSong(s2);
    pl.addSong(s3);
    pl.addSong(s4);

    CHECK(pl.getTotalScore() == 114);

    delete s1;
    delete s2;
    delete s3;
    delete s4;
}

TEST_CASE("Playlist_005") {
    Playlist A("A");
    Playlist B("B");

    Song a1(1,"s1","a","al",200,4,"u");
    Song a2(2,"s2","a","al",200,1,"u");
    Song a3(3,"s3","a","al",200,3,"u");
    Song a4(4,"s4","a","al",200,5,"u");

    Song b1(5,"t1","b","al",200,1,"u");
    Song b2(6,"t2","b","al",200,2,"u");
    Song b3(7,"t3","b","al",200,3,"u");

    A.addSong(&a1);
    A.addSong(&a2);
    A.addSong(&a3);
    A.addSong(&a4);

    B.addSong(&b1);
    B.addSong(&b2);
    B.addSong(&b3);

    CHECK(A.compareTo(B, 2) == true);
    CHECK(B.compareTo(A, 2) == false);
}

TEST_CASE("Playlist_006")
{
    Playlist pl("Test");

    Song s1(1,"S1","A","X",50,10,"u");
    Song s2(2,"S2","A","X",80,10,"u");
    Song s3(3,"S3","A","X",60,10,"u");
    Song s4(4,"S4","A","X",120,10,"u");
    Song s5(5,"S5","A","X",90,10,"u");

    pl.addSong(&s1);
    pl.addSong(&s2);
    pl.addSong(&s3);
    pl.addSong(&s4);
    pl.addSong(&s5);

    std::ostringstream out;
    std::streambuf* oldCout = std::cout.rdbuf(out.rdbuf());

    pl.playRandom(2);

    std::cout.rdbuf(oldCout);

    CHECK(out.str() == "S3-A,S4-A");
}

TEST_CASE("Playlist_007")
{
    Playlist pl("Test");

    Song s1(1,"S1","A","X",50,10,"u");
    Song s2(2,"S2","A","X",60,10,"u");
    Song s3(3,"S3","A","X",30,10,"u");
    Song s4(4,"S4","A","X",90,10,"u");
    Song s5(5,"S5","A","X",100,10,"u");

    pl.addSong(&s1);
    pl.addSong(&s2);
    pl.addSong(&s3);
    pl.addSong(&s4);
    pl.addSong(&s5);

    CHECK(pl.playApproximate(1) == 50);
}
