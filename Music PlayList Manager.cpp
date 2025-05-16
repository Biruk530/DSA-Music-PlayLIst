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

/* Function implementations 
   start by Addishiwot Abdisa creating "save" and "load" functions*/
void save() {
    ofstream file(fileName);
    for (Node* temp = head; temp; temp = temp->next)
        file << temp->song->id << "|" << temp->song->title << "|" << temp->song->artist << "\n";
    file.close();
}

void load() {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {
        size_t p1 = line.find('|'), p2 = line.find('|', p1+1);
        if (p1 == string::npos || p2 == string::npos) continue;

        Song* s = new Song{stoi(line.substr(0, p1)),
                         line.substr(p1+1, p2-p1-1),
                         line.substr(p2+1)};
        Node* newNode = new Node{s, tail, nullptr};

        (head ? tail->next : head) = newNode;
        tail = newNode;
        if (s->id >= nextId) nextId = s->id + 1;
    }
    current = head;
    file.close();
}
/*Crete the funtion that work for show the list and add multiple and single songs 
Complet by Biruk Tibebe*/
void show() {
    if (!head) cout << "Playlist is empty\n";
    else for (Node* temp = head; temp; temp = temp->next)
        cout << temp->song->id << ". " << temp->song->title
             << (temp == current ? " [PLAYING]" : "") << "\n";
}

void addSong(string title, string artist, bool saveToFile) {
    Node* newNode = new Node{new Song{nextId++, title, artist}, tail, nullptr};
    (head ? tail->next : head) = newNode;
    tail = newNode;
    if (saveToFile) save();
}

void addMultipleSongs() {
    int count;
    cout << "How many songs to add? ";
    cin >> count;
    cin.ignore();

    for (int i = 0; i < count; i++) {
        string title, artist;
        cout << "\nSong #" << i+1 << ":\n";
        cout << "Title: "; getline(cin, title);
        cout << "Artist: "; getline(cin, artist);
        addSong(title, artist, false);
    }
    save();
    cout << "\nAdded " << count << " songs!\n";
}
// added play next and previous functions by Bahiru
void playNext() {
    if (!current) cout << "Playlist empty\n";
    else if (repeatMode) cout << "Repeating: " << current->song->title << "\n";
    else if (current->next) cout << "Now playing: " << (current = current->next)->song->title << "\n";
    else cout << "End of playlist\n";
}

void playPrevious() {
    if (!current) cout << "Playlist empty\n";
    else if (current->prev) cout << "Now playing: " << (current = current->prev)->song->title << "\n";
    else cout << "Start of playlist\n";
}
// added shuffle function by Bereket
void shuffle() {
    srand(time(0));
    int count = 0;
    for (Node* t = head; t; t = t->next) count++;
    for (int i = count-1; i > 0; i--) {
        Node *a = head, *b = head;
        for (int k = i; k--; a = a->next);
        for (int k = rand()%(i+1); k--; b = b->next);
        swap(a->song, b->song);
    }
    save();
}