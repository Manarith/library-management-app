#include <iostream>
#include "Library.h"

int main() {
    Library lib;
    int choice, choice_user;
    std::string title, author, name;

    while (true) {
        lib.showActiveUser();
        std::cout << "\n1. Add Book\n2. List Books\n3. Search\n4. Borrow book\n5. Return book\n6. User interface\n0. Exit\n";
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

            case 6:
                std::cout << "\n1. Add user.\n2. List users.\n3. Select user.\n0. Back";
                std::cin >> choice_user;
                std::cin.ignore();

                switch (choice_user) {
                    case 1:
                        std::cout << "User name: ";
                        std::getline(std::cin, name);
                        lib.addUser(name);
                        break;

                    case 2:
                        lib.listUsers();
                        break;

                    case 3:
                        std::cout << "User name to login: ";
                        std::getline(std::cin, name);
                        lib.setActiveUser(name);
                        break;

                    case 0:
                        break;
                }
                break;
                
            case 0:
                return 0;
        }
    }
}