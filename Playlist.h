#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "main.h"
#include "BotkifyLinkedList.h"

// =======================
// Class Song
// =======================
class Song
{
#ifdef TESTING
    friend class TestHelper;    
#endif

private:
    int id;
    string title;
    string artist;
    string album;
    int duration;
    int score;
    string url;
public:
    Song(int id,
         string title,
         string artist,
         string album,
         int duration,
         int score,
         string url);

    int getID() const;
    int getDuration() const;
    int getScore() const;

    string toString() const;
};

// =======================
// Class Playlist
// =======================
class Playlist
{
#ifdef TESTING
    friend class TestHelper;
#endif

private:
    string name;
    BotkifyLinkedList<Song*> lstSong;
    int size;
public:
    Playlist(string name);
    Playlist(const Playlist& other); // Dòng const để đảm bảo mình chỉ có thể xem thôi chứ không sửa được

    int getSize() const;
    bool empty() const;
    void clear();

    void addSong(Song* s);
    void removeSong(int index);
    Song* getSong(int index) const;
    BotkifyLinkedList<Song*> getlstSong();

    Song* playNext();
    Song* playPrevious();

    int getTotalScore();
    bool compareTo(Playlist p, int numSong);

    void playRandom(int index);
    int playApproximate(int step);
};

#endif // PLAYLIST_H
