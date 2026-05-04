#include "Library.h"
#include "BookFactory.h"
#include <iostream>
#include <fstream>
#include <sstream>

Library::Library() {
    Library::loadBooks();
    Library::loadUsers();
}

Library::~Library() {
    Library::saveBooks();
    Library::saveUsers();
}

void Library::addUser(const std::string name) {
    users.push_back(User(name));
    std::cout << "User " << name << " added!\n";
}

void Library::listUsers() {
    for (auto& u : users) {
        std::cout <<"User: "<< u.user_name << "\n";
    }
}

User* Library::findUser(const std::string name) {
    for (auto& u : users) {
        if (u.user_name == name) return &u;
    }
    return nullptr;
}

void Library::setActiveUser(const std::string name) {
    User* user = findUser(name);

    if (user) {
        active_user = user;
        std::cout << "Active user set to: " << name << "\n";
    }
    else {
        std::cout << "User not found!\n";
    }
}

void Library::showActiveUser() {
    if (active_user) {
        std::cout << "Current user: " << active_user->user_name << "\n";
    }
    else {
        std::cout << "No active user.\n";
    }
}

void Library::loadBooks() {
    std::ifstream file(books_filename);
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

void Library::loadUsers() {
    std::ifstream file(users_filename);
    if (!file) return;

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string username, title;
        getline(ss, username, '|');
        getline(ss, title); // To implement

        users.push_back(User(username));
    }
}

void Library::saveBooks() {
    std::ofstream file(books_filename);
    for (auto& b : books) {
        file << b.title << "|" << b.author << "|" << (b.isAvailable ? "1" : "0") << "\n";
    }
}

void Library::saveUsers() {
    std::ofstream file(users_filename);
    for (auto& u : users) {
        file << u.user_name << "|" /* << u.title */ << "\n";
    }
}

void Library::addBook(const std::string title, const std::string author) {
    books.push_back(BookFactory::createBook(title, author));
    std::cout << "Book added!\n";
}

void Library::listBooks() {
    for (auto &b : books) {
        std::cout << b.title << " by " << b.author
                  << (b.isAvailable ? " [Available]" : " [Borrowed]") << std::endl;
    }
}

void Library::searchBook(const std::string keyword) {
    for (auto &b : books) {
        if (b.title.find(keyword) != std::string::npos) {
            std::cout << "Found: " << b.title << " by " << b.author << std::endl;
        }
    }
}

void Library::borrowBook(const std::string title) {
    for (auto &b : books) {
        if (b.title == title && b.isAvailable) {
            b.isAvailable = false;
            std::cout << "Borrowed successfully!\n";
            return;
        }
    }
    std::cout << "Book not available.\n";
}

void Library::returnBook(const std::string title) {
    for (auto &b : books) {
        if (b.title == title && !b.isAvailable) {
            b.isAvailable = true;
            std::cout << "Returned successfully!\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}