#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    int id;
    string address;
    string owner;

public:
    Apartment(int id, string address, const string owner) {
        this->id = id;
        this->address = address;
        this->owner = owner;
    }

    Apartment(const Apartment& other) {
        id = other.id;
        address = other.address;
        owner = other.owner;
    }

    void display() const {
        cout<<"Apartment ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Owner: "<<owner<<endl;
    }
};

int main() {
    Apartment apt1(101, "555 Main Road", "ARQ");
    
    cout<<"Original Apartment Details:"<<endl;
    apt1.display();
    
    Apartment apt2 = apt1;
    
    cout <<"\nCopied Apartment Details (New Agent):"<<endl;
    apt2.display();
    
    return 0;
}