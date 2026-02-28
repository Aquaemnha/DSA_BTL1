#include "Playlist.h"

// =======================
// Song implementation
// =======================

Song::Song(int id,
           string title,
           string artist,
           string album,
           int duration,
           int score,
           string url)
{
    // TODO: Student implementation
}

int Song::getID() const
{
    // TODO: Student implementation
    return 0;
}

int Song::getDuration() const
{
    // TODO: Student implementation
    return 0;
}

int Song::getScore() const
{
    // TODO: Student implementation
    return 0;
}

string Song::toString() const
{
    // TODO: Student implementation
    return "";
}

// =======================
// Playlist implementation
// =======================

Playlist::Playlist(string name)
{
    // TODO: Student implementation
}

int Playlist::size() const
{
    // TODO: Student implementation
    return 0;
}

bool Playlist::empty() const
{
    // TODO: Student implementation
    return true;
}

void Playlist::clear()
{
    // TODO: Student implementation
}

void Playlist::addSong(Song* s)
{
    // TODO: Student implementation
}

void Playlist::removeSong(int index)
{
    // TODO: Student implementation
}

Song* Playlist::getSong(int index) const
{
    // TODO: Student implementation
    return nullptr;
}

// =======================
// Playing control
// =======================

Song* Playlist::playNext()
{
    // TODO: Student implementation
    return nullptr;
}

Song* Playlist::playPrevious()
{
    // TODO: Student implementation
    return nullptr;
}

// =======================
// Score-related
// =======================

int Playlist::getTotalScore()
{
    // TODO: Student implementation
    return 0;
}

bool Playlist::compareTo(const Playlist& pp, int numSong)
{
    // TODO: Student implementation
    return false;
}

// =======================
// Advanced playing modes
// =======================

void Playlist::playRandom(int index)
{
    // TODO: Student implementation
}

int Playlist::playApproximate(int step)
{
    // TODO: Student implementation
    return 0;
}
