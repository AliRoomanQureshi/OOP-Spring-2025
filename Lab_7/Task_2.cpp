#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id, const string& name, double p, int stock = 0)
        : productID(id), productName(name), price(p), stockQuantity(stock) {}

    virtual double applyDiscount() {
        return price; 
    }

    virtual double calculateTotalPrice(int quantity) {
        return applyDiscount() * quantity;
    }

    virtual void displayProductInfo() {
        cout<<"Product ID:"<<productID<<", Name:"<<productName<<", Price:"<<price<<", Stock:"<<stockQuantity<<endl;
    }

    double operator+(const Product& other) const {
        return this->price + other.price;
    }

    friend ostream& operator<<(ostream& out, const Product& p) {
        out<<"Product ID:"<<p.productID<<", Name:"<<p.productName<<", Price:"<<p.price<<", Stock:"<<p.stockQuantity;
        return out;
    }

    virtual ~Product() {}
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, const string& name, double p, int stock, int warranty, const string& b)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout<<", Warranty:"<<warrantyPeriod<<" years, Brand:"<<brand<<endl;
    }
};

class Clothing : public Product {
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, const string& name, double p, int stock, const string& sz, const string& clr, const string& fabric)
        : Product(id, name, p, stock), size(sz), color(clr), fabricMaterial(fabric) {}

    double applyDiscount() override {
        return price * 0.9;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout<<", Size:"<<size<<", Color:"<<color<<", Fabric:"<<fabricMaterial<<endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, const string& name, double p, int stock, const string& expDate, int cal)
        : Product(id, name, p, stock), expirationDate(expDate), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        if (quantity > 5) {
            return (price * quantity) * 0.85;
        }
        return price * quantity;
    }

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout<<", Expiration Date:"<<expirationDate<<", Calories:"<<calories<<" kcal"<<endl;
    }
};

class Book : public Product {
    string author;
    string genre;

public:
    Book(int id, const string& name, double p, int stock, const string& auth, const string& g)
        : Product(id, name, p, stock), author(auth), genre(g) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout<<", Author:"<<author<<", Genre:"<<genre<<endl;
    }
};

int main() {
    Electronics laptop(201, "HP ZBook G16", 1200, 10, 2, "HP");
    Clothing tshirt(202, "T-Shirt", 25, 50, "M", "Blue", "Cotton");
    FoodItem chocolate(203, "Dairy Milk", 5, 100, "2025-12-31", 200);
    Book novel(204, "The Alchemist", 15, 30, "Paul Coelho", "Classic");

    cout<<"--- Product Information ---"<<endl;
    laptop.displayProductInfo();
    tshirt.displayProductInfo();
    chocolate.displayProductInfo();
    novel.displayProductInfo();

    cout<<"\n--- Price Calculation ---"<<endl;
    cout<<"Total price for 3 chocolates:"<<chocolate.calculateTotalPrice(3)<<endl;
    cout<<"Total price for 6 chocolates:"<<chocolate.calculateTotalPrice(6)<<endl; 
    cout<<"\n--- Operator Overloading ---"<<endl;
    double combinedPrice = laptop + tshirt;
    cout<<"Combined Price of Laptop and T-Shirt:"<<combinedPrice<<endl;

    cout<<"\n--- Overloaded Output Operator ---"<<endl;
    cout<<laptop<<endl;

    return 0;
}
