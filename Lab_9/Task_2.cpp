#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double p) : dishName(name), price(p) {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double p) : MenuItem(name, p) {}

    void showDetails() const override {
        cout << "Appetizer: " << dishName << " - Price: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation: Light seasoning, quick fry, and plating.\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double p) : MenuItem(name, p) {}

    void showDetails() const override {
        cout << "Main Course: " << dishName << " - Price: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparation: Full cooking, marination, garnishing, and serving.\n";
    }
};

int main() {
    MenuItem* menu[2];
    menu[0] = new Appetizer("Spring Rolls", 6.50);
    menu[1] = new MainCourse("Grilled Chicken", 15.99);

    for (int i = 0; i < 2; i++) {
        menu[i]->showDetails();
        menu[i]->prepare();
        cout << endl;
        delete menu[i];
    }

    return 0;
}