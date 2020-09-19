#include<iostream>
#include<string>


using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
}

void PlaylistNode::InsertAfter(PlaylistNode* node2) {
    PlaylistNode* temp = this -> nextNodePtr;
    this -> nextNodePtr = node2;
    node2 -> SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* node2) {
    this->nextNodePtr = node2;
    return;
}

string PlaylistNode::GetID() {
    return uniqueID;
}

string PlaylistNode::GetSongName(){
    return songName;
}

string PlaylistNode::GetArtistName(){
    return artistName;
}

int PlaylistNode::GetSongLength(){
    return songLength;
}
PlaylistNode* PlaylistNode::GetNext() {
    return nextNodePtr;
}

//sample output::
// Unique ID: S123
// Song Name: Peg
// Artist Name: Steely Dan
// Song Length (in seconds): 237

void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
