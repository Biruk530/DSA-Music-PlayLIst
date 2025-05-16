


















void addSong(string title, string artist, bool saveToFile = true);
void addMultipleSongs();







































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
