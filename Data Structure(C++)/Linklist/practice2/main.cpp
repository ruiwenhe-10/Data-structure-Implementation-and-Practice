#include<iostream>
#include<string>

using namespace std;

#include "Playlist.h"


void PrintMenu(string title) {
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
    return;
}

int main() {
    

char option; 

PlaylistNode* head = 0;
PlaylistNode* tail = 0;

PlaylistNode* currobj = 0;

PlaylistNode* addobj = 0;

PlaylistNode* tempobj = 0;
PlaylistNode* setempobj = 0;

int number = 1;

int currpos = 0;                            //variables for change position
int newpos = 0;
int count = 0;

string UID;                                 //variables for add song
string sname;
string artname;
int slength;

string title;

string listtitle;
cout << "Enter playlist's title:" << endl;

getline(cin, listtitle);

cout << endl;

PrintMenu(listtitle);
cin >> option;
cout << endl;
while (option != 'a' && option != 'd' && option != 'c' && option != 's' && option != 't' && option != 'o' && option != 'q') {
    PrintMenu(listtitle);
    cin >> option;
}
while (option != 'q') {
  
  if (option == 'o') {                      //when option is "Output full Playlist"
      if (head == 0) {
          cout << listtitle << " - OUTPUT FULL PLAYLIST" << endl;
          cout << "Playlist is empty";      //empty list when head point to nothing
          cout << endl << endl;
      }   
      else {
          cout << listtitle << " - OUTPUT FULL PLAYLIST" << endl;
          for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
              cout << number << "." << endl;
              currobj -> PrintPlaylistNode();
              cout << endl;
              ++number;
          }
          number = 1;
      }
    }  // end of Output full Playlist
    
    if(option == 'a') {                     //when option is "a - Add song"
        
        cout << "ADD SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        cin >> UID;
        cout << "Enter song's name:" << endl;
        cin.ignore();
        getline(cin,sname);
        cout << "Enter artist's name:" << endl;
        getline(cin, artname);
        cout << "Enter song's length (in seconds):" << endl;
        cin >> slength;
        cout << endl;
        addobj = new PlaylistNode(UID, sname, artname, slength);
        if (head == 0) {                    //check if list is empty
            head = addobj;
            tail = addobj;
        }
        else {
            tail -> SetNext(addobj);
            tail = addobj;
        }
        ++count;
    }                                       //end of add song
    
    if(option == 'd') {
        
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        cin >> UID;
        
        if (head == 0) {
            cout << "Playlist is empty" << endl;
        }
        else if (head == tail) {            //when there is only one object in the list
            sname = head -> GetSongName();
            head = 0;
        }
        else if (head -> GetID() == UID) {  //when it is the first term
            sname = head -> GetSongName();
            tempobj = head;
            head = head -> GetNext();
            delete tempobj;
        }
        else if (tail -> GetID() == UID) {  //when it is the last term
            sname = tail -> GetSongName();
            tempobj = tail;
            for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                if (currobj -> GetNext() == tail) {
                tail = currobj;
                currobj -> SetNext(0);
                }
            }
            delete tempobj;
        }
        else {
            PlaylistNode* preobj = head;
            for (currobj = head -> GetNext(); currobj != 0; currobj = currobj -> GetNext()) {
                if(currobj -> GetID() == UID) {
                    sname = currobj -> GetSongName();
                    preobj -> SetNext(currobj -> GetNext());
                    delete currobj;
                }
                preobj = preobj -> GetNext();
            }
        }
        cout << '"' << sname << '"' << " removed." << endl << endl;
        --count;
    }                                       // end of remove song
    
    
// CHANGE POSITION OF SONG
// Enter song's current position:
// 3
// Enter new position for song:
// 2
// "Canned Heat" moved to position 2
    if(option == 'c') {
        int i = 1;
        cout << "CHANGE POSITION OF SONG" << endl;
        cout << "Enter song's current position:" << endl;
        cin >> currpos;
        cout << "Enter new position for song:" << endl;
        cin >> newpos;
        if (currpos != newpos) {
            
            if(currpos == 1) {                      //move head
            i = 1;
                if (newpos >= count) {              //move head to tail
                    title = head -> GetSongName();
                    tempobj = head;
                    head = head -> GetNext();
                    tail -> SetNext(tempobj);
                    tail = tempobj;
                    tempobj -> SetNext(0);
                }
                else {                              //  currpos = 1 < newpos < count
                    for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                        if (i == newpos) {
                            title = head -> GetSongName();
                            tempobj = head;
                            head = head -> GetNext();
                            currobj -> InsertAfter(tempobj);
                        }
                     ++i;   
                    }
                    
                }
            }
            
            else if (currpos == count) {                 //move tail
                i = 1;
                for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                        if (currobj -> GetNext() == tail) {
                            tempobj = tail;
                            title = tempobj -> GetSongName();
                            tail = currobj;
                            currobj -> SetNext(0);
                        }
                }
                if (newpos <= 1) {                  //move tail to head
                            setempobj = head;
                            head = tempobj;
                            tempobj -> SetNext(setempobj);
                }
                else {                              // 1 < newpos < currpos = count
                    for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {       
                        if (i == newpos - 1) {
                            currobj -> InsertAfter(tempobj);
                        }
                        ++i;
                    }
                    
                }
            
            }
            
            else if (currpos < newpos) {                 //FIX ME !!!!!!!
                i = 1;
                for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                    if (i == currpos - 1) {
                        title = (currobj -> GetNext()) -> GetSongName();
                        tempobj = currobj -> GetNext();
                        currobj -> SetNext((currobj -> GetNext()) -> GetNext());
                    }
                  ++i;  
                }
                i = 1;
                for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                    if (i == newpos - 1) {
                        currobj -> InsertAfter(tempobj);
                    }
                    ++i;
                }
                if (newpos == count) {
                    tail = tempobj;
                }
               
            }
            
            else if (currpos > newpos) {
                 i = 1;
                for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                    if (i == currpos - 1) {
                        title = (currobj -> GetNext()) -> GetSongName();
                        tempobj = currobj -> GetNext();
                        currobj -> SetNext((currobj -> GetNext()) -> GetNext());
                    }
                  ++i;  
                }
                i = 1;
                for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
                    if (i == newpos - 1) {
                        currobj -> InsertAfter(tempobj);
                    }
                    ++i;
                }
                if (newpos == 1) {
                    setempobj = head;
                    head = tempobj;
                    tempobj -> SetNext(setempobj);
                }
                
            }
        }
    cout << '"' << title << '"' << " moved to position " << newpos << endl << endl; 
        
    }
    
// OUTPUT SONGS BY SPECIFIC ARTIST
// Enter artist's name:
// Janet Jackson

// 2.
// Unique ID: JJ234
// Song Name: All For You
// Artist Name: Janet Jackson
// Song Length (in seconds): 391

// 4.
// Unique ID: JJ456
// Song Name: Black Eagle
// Artist Name: Janet Jackson
// Song Length (in seconds): 197

    if (option == 's') {
        int c = 1;
        string aname;
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        cin.ignore();
        getline(cin, aname);
        cout << endl;
        for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
            if (aname == currobj -> GetArtistName()) {
                cout << c << '.' << endl;
                currobj -> PrintPlaylistNode();
                cout << endl;
            }
         ++c;   
        }
            
    }
    
    if (option == 't') {
        int sum = 0;
        for (currobj = head; currobj != 0; currobj = currobj -> GetNext()) {
            sum = sum + currobj -> GetSongLength();
        }
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: " << sum << " seconds" << endl << endl;
    }
  
        PrintMenu(listtitle);
        cin >> option;
        cout << endl;
        
    
}


    


return 0;

    
}