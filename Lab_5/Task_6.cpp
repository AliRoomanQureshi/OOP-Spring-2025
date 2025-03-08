#include <iostream>
#include <string>

using namespace std;

class Level {
private:
    string levelName;
    int difficulty;

public:
    Level(const string& name, int difficulty) : levelName(name), difficulty(difficulty) {}

    void displayLevelDetails() const {
        cout<<"Level Name: "<<levelName<<endl;
        cout<<"Difficulty: "<<difficulty<<endl;
        cout<<"----------------------"<<endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels[10];
    int levelCount;

public:
    VideoGame(const string& title, const string& genre) : title(title), genre(genre), levelCount(0) {}

    ~VideoGame() {
        for (int i=0;i<levelCount;i++) {
            delete levels[i];
        }
    }

    void addLevel(const string& name, int difficulty) {
        if (levelCount < 10) {
            levels[levelCount] = new Level(name, difficulty);
            levelCount++;
        }
    }

    void displayGameDetails() const {
        cout<<"Game Title: "<<title<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"Levels:"<<endl;
        cout<<"----------------------"<<endl;
        if (levelCount == 0) {
            cout<<"No levels available."<<endl;
        } else {
            for (int i=0;i<levelCount;i++) {
                levels[i]->displayLevelDetails();
            }
        }
    }
};

int main() {
    VideoGame game("Grand theft Auto V", "Open-World");

    game.addLevel("Heist 1", 3);
    game.addLevel("Heist 2", 5);
    game.addLevel("Heist 3", 7);

    game.displayGameDetails();

    return 0;
}
