#include "User.h"

User::User(std::string n) : user_name(n) {};

void User::borrowBook(const std::string& title) {
	borrowed_books.push_back(title);
}

void User::returnBook(const std::string& title) {
    for (auto it = borrowed_books.begin(); it != borrowed_books.end(); ++it) {
        if (*it == title) {
            borrowed_books.erase(it);
            return;
        }
    }
}