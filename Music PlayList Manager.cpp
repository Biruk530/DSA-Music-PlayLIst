#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//create the stracture for the nodes
struct Song { int id; string title, artist; };
struct Node { Song* song; Node* prev, *next; };

//default value of linked list
Node *head = nullptr, *tail = nullptr, *current = nullptr;
bool repeatMode = false;
const string fileName = "playlist.txt";
int nextId = 1;

// Function declarations
void save();
void load();
void show();
void addSong(string title, string artist, bool saveToFile = true);
void addMultipleSongs();
void playNext();
void playPrevious();
void shuffle();