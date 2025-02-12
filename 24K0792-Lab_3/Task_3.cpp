#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookList[100];
    string borrowedBooks[100];
    string availableBooks[100];
    int totalBooks, borrowedCount, availableCount;

public:
    Library() {
        totalBooks = 0;
        borrowedCount = 0;
        availableCount = 0;
    }

    void addBook(string bookName) {
        if (totalBooks < 100) {
            bookList[totalBooks] = bookName;
            availableBooks[availableCount] = bookName;
            totalBooks++;
            availableCount++;
            cout<<bookName<<" added to the library.\n";
        } else {
            cout<<"Library is full! Cannot add more books.\n";
        }
    }

    void lendBook(string bookName) {
        for (int i=0; i<availableCount;i++) {
            if (availableBooks[i] == bookName) {
                borrowedBooks[borrowedCount] = bookName;
                borrowedCount++;

                for (int j=i;j<availableCount-1;j++) {
                    availableBooks[j] = availableBooks[j + 1];
                }
                availableCount--;

                cout<<bookName<<" has been borrowed.\n";
                return;
            }
        }
        cout<<bookName<<" is not available for borrowing.\n";
    }

    void returnBook(string bookName) {
        for (int i=0;i<borrowedCount;i++) {
            if (borrowedBooks[i] == bookName) {
                availableBooks[availableCount] = bookName;
                availableCount++;

                for (int j=i;j<borrowedCount-1;j++) {
                    borrowedBooks[j] = borrowedBooks[j+1];
                }
                borrowedCount--;
                cout<<bookName <<" has been returned.\n";
                return;
            }
        }
        cout<<bookName<<" was not borrowed.\n";
    }

    void displayAvailableBooks() {
        cout<<"Available Books:\n";
        for (int i=0;i<availableCount;i++) {
            cout<<"- "<<availableBooks[i]<<"\n";
        }
    }

    void displayBorrowedBooks() {
        cout<<"Borrowed Books:\n";
        for (int i=0;i<borrowedCount;i++) {
            cout<<"- "<<borrowedBooks[i]<<"\n";
        }
    }
};

int main() {
    Library lib;
    lib.addBook("The Alchemist");
    lib.addBook("1984");
    lib.addBook("And then there were none");

    lib.displayAvailableBooks();

    lib.lendBook("1984");
    lib.displayAvailableBooks();
    lib.displayBorrowedBooks();

    lib.returnBook("1984");
    lib.displayAvailableBooks();
    lib.displayBorrowedBooks();

    return 0;
}
