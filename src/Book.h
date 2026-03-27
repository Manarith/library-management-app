#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isAvailable;

    Book(string t, string a, bool available = true) {
        title = t;
        author = a;
        isAvailable = available;
    }
};

#endif