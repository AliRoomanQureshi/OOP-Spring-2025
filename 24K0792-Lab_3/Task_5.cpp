#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[100];
    string currentlyPlayingSong;
    int songCount;

public:
    MusicPlayer() {
        songCount = 0;
        currentlyPlayingSong = "No song is playing.";
    }

    void addSong(string songName) {
        if (songCount < 100) {
            playlist[songCount] = songName;
            songCount++;
            cout<<songName<<" added to the playlist.\n";
        } else {
            cout<<"Playlist is full. Cannot add more songs.\n";
            }
    }

    void removeSong(string songName) {
        int index = -1;
        for (int i=0; i<songCount; i++) {
            if (playlist[i] == songName) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i=index; i<songCount-1; i++) {
                playlist[i] = playlist[i+1];
            }
            songCount--;
            cout<<songName<<" removed from the playlist.\n";
            if (currentlyPlayingSong == songName){ 
                currentlyPlayingSong = "No song is playing.";
            }
        } else { 
            cout<<songName<<" not found in the playlist.\n";
            }
    }

    void playSong(string songName) {
        bool found = false;
        for (int i=0; i<songCount; i++) {
            if (playlist[i] == songName) {
                currentlyPlayingSong = songName;
                cout<<"Now playing: "<<songName<<"\n";
                found = true;
                break;
            }
        }
        if (!found){ 
            cout<<songName<<" is not in the playlist.\n";
            }
    }

    void displayPlaylist() {
        if (songCount == 0){ 
            cout<<"Playlist is empty.\n";
        }
        else {
            cout<<"Playlist:\n";
            for (int i=0; i<songCount; i++) {
                cout<<i+1<<". "<<playlist[i]<<"\n";
            }
        }
    }
};

int main() {
    MusicPlayer mp;
    mp.addSong("Play with fire");
    mp.addSong("Believer");
    mp.displayPlaylist();
    mp.playSong("Believer");
    mp.removeSong("Play with fire");
    mp.displayPlaylist();
    return 0;
}