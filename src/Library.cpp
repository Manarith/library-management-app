#include "Library.h"
#include "BookFactory.h"
#include <iostream>
#include <fstream>
#include <sstream>

Library::Library() {
    Library::loadBooks();
}

Library::~Library() {
    Library::saveBooks();
}

void Library::loadBooks() {
    std::ifstream file(filename);
    if (!file) return;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string title, author, availableStr;
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, availableStr);

        bool available = (availableStr == "1");
        books.push_back(Book(title, author, available));
    }
}

void Library::saveBooks() {
    std::ofstream file(filename);
    for (auto& b : books) {
        file << b.title << "|" << b.author << "|" << (b.isAvailable ? "1" : "0") << "\n";
    }
}

void Library::addBook(std::string title, std::string author) {
    books.push_back(BookFactory::createBook(title, author));
    std::cout << "Book added!\n";
}

void Library::listBooks() {
    for (auto &b : books) {
        std::cout << b.title << " by " << b.author
                  << (b.isAvailable ? " [Available]" : " [Borrowed]") << std::endl;
    }
}

void Library::searchBook(std::string keyword) {
    for (auto &b : books) {
        if (b.title.find(keyword) != std::string::npos) {
            std::cout << "Found: " << b.title << " by " << b.author << std::endl;
        }
    }
}

void Library::borrowBook(std::string title) {
    for (auto &b : books) {
        if (b.title == title && b.isAvailable) {
            b.isAvailable = false;
            std::cout << "Borrowed successfully!\n";
            return;
        }
    }
    std::cout << "Book not available.\n";
}

void Library::returnBook(std::string title) {
    for (auto &b : books) {
        if (b.title == title && !b.isAvailable) {
            b.isAvailable = true;
            std::cout << "Returned successfully!\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}