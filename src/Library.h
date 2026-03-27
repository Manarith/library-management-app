#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(std::string title, std::string author);
    void listBooks();
    void searchBook(std::string keyword);
    void borrowBook(std::string title);
    void returnBook(std::string title);
};

#endif