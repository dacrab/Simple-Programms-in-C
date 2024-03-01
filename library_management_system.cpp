#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> library;

void addBook(string title, int copies) {
    library[title] += copies;
    cout << "Book added: " << title << " (" << copies << " copies)" << endl;
}

void removeBook(string title, int copies) {
    if (library.find(title) != library.end()) {
        if (library[title] >= copies) {
            library[title] -= copies;
            cout << "Book removed: " << title << " (" << copies << " copies)" << endl;
        } else {
            cout << "Error: Not enough copies of " << title << " in the library!" << endl;
        }
    } else {
        cout << "Error: " << title << " not found in the library!" << endl;
    }
}

void displayBooks() {
    cout << "Library Inventory:" << endl;
    for (auto &entry : library) {
        cout << entry.first << " - " << entry.second << " copies" << endl;
    }
}

int main() {
    addBook("Introduction to C++", 5);
    addBook("Data Structures and Algorithms", 3);
    addBook("The C Programming Language", 7);

    displayBooks();

    removeBook("Introduction to C++", 2);
    removeBook("Data Structures and Algorithms", 5);

    displayBooks();

    return 0;
}
