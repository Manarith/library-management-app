#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>
#include <string>

class Library {
private:
    std::vector<Book> books;
    const std::string filename = "data/books.txt";

    void loadBooks();
    void saveBooks();

public:
    Library();   //Loads books from "books.txt" when initialized
    ~Library();  //Saves changes to "books.txt" when scope ends

    void addBook(std::string title, std::string author);
    void listBooks();
    void searchBook(std::string keyword);
    void borrowBook(std::string title);
    void returnBook(std::string title);
};

#endif