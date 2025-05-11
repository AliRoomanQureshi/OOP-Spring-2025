#include <iostream>
#include <exception>

using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
    T stock;
    T maxLimit;
public:
    InventoryItem(T max) : stock(0), maxLimit(max) {}

    void setStock(T value) {
        cout << "Attempting to set stock to " << value;
        if (value < 0) {
            cout << "..." << endl;
            throw NegativeStockException();
        } else if (value > maxLimit) {
            cout << " (max " << maxLimit << ")..." << endl;
            throw OverCapacityException();
        }
        cout << "..." << endl;
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Caught general exception - what(): " << e.what() << endl;
    }

    try {
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Caught general exception - what(): " << e.what() << endl;
    }
    return 0;
}
