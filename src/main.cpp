#include <iostream>
#include "Library.h"

int main() {
    Library lib;
    int choice;
    std::string title, author;

    while (true) {
        std::cout << "\n1. Add Book\n2. List Books\n3. Search\n4. Borrow book\n5. Return book\n0. Exit\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                std::cout << "Title: ";
                std::getline(std::cin, title);
                std::cout << "Author: ";
                std::getline(std::cin, author);
                lib.addBook(title, author);
                break;

            case 2:
                lib.listBooks();
                break;

            case 3:
                std::cout << "Search keyword: ";
                std::getline(std::cin, title);
                lib.searchBook(title);
                break;

            case 4:
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                lib.borrowBook(title);
                break;

            case 5:
                std::cout << "Enter title: ";
                std::getline(std::cin, title);
                lib.returnBook(title);
                break;

            case 0:
                return 0;
        }
    }
}