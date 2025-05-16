

















void show();


































void show() {
    if (!head) cout << "Playlist is empty\n";
    else for (Node* temp = head; temp; temp = temp->next)
        cout << temp->song->id << ". " << temp->song->title
             << (temp == current ? " [PLAYING]" : "") << "\n";
}
