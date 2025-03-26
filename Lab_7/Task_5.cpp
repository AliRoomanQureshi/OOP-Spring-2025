#include <iostream>
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int characterID;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(const string& n, int id, int lvl, int hp, const string& weapon = "")
        : name(n), characterID(id), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout << name << " attacks with " << (weaponType.empty() ? "bare hands!" : weaponType) << endl;
    }

    virtual void defend() {
        cout << name << " defends against the attack!" << endl;
    }

    virtual void displayStats() {
        cout << "Character ID: " << characterID << ", Name: " << name 
             << ", Level: " << level << ", HP: " << healthPoints;
        if (!weaponType.empty()) {
            cout << ", Weapon: " << weaponType;
        }
        cout << endl;
    }

    virtual ~Character() {}
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;

public:
    Warrior(const string& n, int id, int lvl, int hp, int armor, int damage)
        : Character(n, id, lvl, hp, "Sword"), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " swings their sword, dealing " << meleeDamage << " melee damage!" << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;

public:
    Mage(const string& n, int id, int lvl, int hp, int mana, int power)
        : Character(n, id, lvl, hp, "Magic Staff"), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " casts a magical barrier, reducing damage!" << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(const string& n, int id, int lvl, int hp, int arrows, int accuracy)
        : Character(n, id, lvl, hp, "Bow"), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        if (arrowCount > 0) {
            cout << name << " shoots an arrow with " << rangedAccuracy << "% accuracy!" << endl;
            arrowCount--;
        } else {
            cout << name << " has no arrows left!" << endl;
        }
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;

public:
    Rogue(const string& n, int id, int lvl, int hp, int stealth, int agil)
        : Character(n, id, lvl, hp, "Daggers"), stealthLevel(stealth), agility(agil) {}

    void displayStats() override {
        Character::displayStats();
        cout << ", Stealth Level: " << stealthLevel << ", Agility: " << agility << endl;
    }
};

int main() {
    Warrior warrior1("Garen", 101, 10, 150, 50, 30);
    Mage mage1("Lux", 102, 9, 100, 200, 40);
    Archer archer1("Ashe", 103, 8, 90, 10, 85);
    Rogue rogue1("Talon", 104, 11, 120, 90, 75);

    cout << "\n--- Character Statistics ---\n";
    warrior1.displayStats();
    mage1.displayStats();
    archer1.displayStats();
    rogue1.displayStats();

    cout << "\n--- Character Actions ---\n";
    warrior1.attack();
    mage1.defend();
    archer1.attack();
    rogue1.displayStats();

    return 0;
}