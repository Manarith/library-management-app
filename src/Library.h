#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <memory>
#include <string>

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;
    User* active_user = nullptr;
    const std::string books_filename = "data/books.txt";
    const std::string users_filename = "data/users.txt";

    void loadBooks();
    void saveBooks();
    void loadUsers();
    void saveUsers();

public:
    Library();   //Loads books from "books.txt" when initialized
    ~Library();  //Saves changes to "books.txt" when scope ends

    void addUser(const std::string name);
    void listUsers();
    void setActiveUser(const std::string name);
    void showActiveUser();
    User* findUser(std::string name);

    void addBook(const std::string title, const std::string author);
    void listBooks();
    void searchBook(const std::string keyword);
    void borrowBook(const std::string title); //to delete
    void returnBook(const std::string title); //to delete
};

#endif