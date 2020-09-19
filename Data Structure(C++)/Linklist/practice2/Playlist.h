#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;



class PlaylistNode {
    private:
    string uniqueID;             //- Initialized to "none" in default constructor
    string songName;             //- Initialized to "none" in default constructor
    string artistName;           //- Initialized to "none" in default constructor
    int songLength;              //- Initialized to 0 in default constructor
    PlaylistNode* nextNodePtr;   //- Initialized to 0 in default constructor
    
    public:
    PlaylistNode();
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);
    void InsertAfter(PlaylistNode* node2);      
    void SetNext(PlaylistNode* node2);          
    string GetID();
    string GetSongName();      
    string GetArtistName();    
    int GetSongLength();    
    PlaylistNode* GetNext();          
    void PrintPlaylistNode();
    
    
};









#endif