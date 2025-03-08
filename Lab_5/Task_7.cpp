#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;

public:
    Product() : id(0), name(""), quantity(0) {}

    void inputProduct() {
        cout<<"Enter Product ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Enter Product Name: ";
        getline(cin, name);
        cout<<"Enter Quantity in Stock: ";
        cin>>quantity;
    }

    void displayProduct() const {
        cout<<"ID: "<<id<<", Name: "<<name<<", Quantity: "<<quantity<<endl;
    }

    string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }
};

void sortProductsByName(Product products[], int count) {
    for (int i=0;i<count-1;++i) {
        for (int j=i+1;j<count;++j) {
            if (products[i].getName() > products[j].getName()) {
                swap(products[i], products[j]);
            }
        }
    }
}

void searchProductByID(const Product products[], int count, int searchID) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (products[i].getID() == searchID) {
            cout << "Product Found: ";
            products[i].displayProduct();
            found = true;
            break;
        }
    }
    if (!found) {
        cout<<"Product with ID "<<searchID<<" not found."<<endl;
    }
}

int main() {
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    cout<<"Enter number of products: ";
    cin>>productCount;
    cin.ignore();

    for (int i=0;i<productCount;++i) {
        cout<<"Enter details for product "<<i+1<<endl;
        products[i].inputProduct();
    }

    cout<<"\nSorting products alphabetically by name...\n";
    sortProductsByName(products, productCount);

    cout<<"\nSorted Products List:\n";
    for (int i=0;i<productCount;++i) {
        products[i].displayProduct();
    }

    int searchID;
    cout<<"\nEnter product ID to search: ";
    cin>>searchID;
    searchProductByID(products, productCount, searchID);
    return 0;
}
