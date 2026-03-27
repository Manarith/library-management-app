#include "Library.h"
#include "BookFactory.h"
#include <iostream>

using namespace std;

void Library::addBook(string title, string author) {
    books.push_back(BookFactory::createBook(title, author));
    cout << "Book added!\n";
}

void Library::listBooks() {
    for (auto &b : books) {
        cout << b.title << " by " << b.author
             << (b.isAvailable ? " [Available]" : " [Borrowed]") << endl;
    }
}

void Library::searchBook(string keyword) {
    for (auto &b : books) {
        if (b.title.find(keyword) != string::npos) {
            cout << "Found: " << b.title << " by " << b.author << endl;
        }
    }
}

void Library::borrowBook(string title) {
    for (auto &b : books) {
        if (b.title == title && b.isAvailable) {
            b.isAvailable = false;
            cout << "Borrowed successfully!\n";
            return;
        }
    }
    cout << "Book not available.\n";
}

void Library::returnBook(string title) {
    for (auto &b : books) {
        if (b.title == title && !b.isAvailable) {
            b.isAvailable = true;
            cout << "Returned successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}