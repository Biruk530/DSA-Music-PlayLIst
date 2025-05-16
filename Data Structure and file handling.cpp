#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Song { int id; string title, artist; };
struct Node { Song* song; Node* prev, *next; };

Node *head = nullptr, *tail = nullptr, *current = nullptr;
bool repeatMode = false;
const string fileName = "playlist.txt";
int nextId = 1;


void save();
void load();








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
