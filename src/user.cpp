#include "user.h"

User::User(std::string n) : name(n) {};

void borrowedBook(const std::string& title) {
	borrowedBooks.pushback(title);
}

void returnBook(const std::string& title) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if (*it == title) {
            borrowedBooks.erase(it);
            return;
        }
    }
}