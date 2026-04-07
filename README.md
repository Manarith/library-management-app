# library-management-app
A simple console-based Library Management System built in C++. It demonstrates programming concepts like Object-Oriented Programming (OOP), file handling, basic data management and design patterns.

### Features

**Book Management**

Add new books (title & author)
View all books in the library
Search books by keyword

**Borrowing System**

Borrow available books
Return borrowed books
Track availability status

**File Persistence (data/books.txt)**

Automatically loads books from file on startup
Saves all changes to file on exit
Data persists between program runs

**Compile:**

g++ src/*.cpp -o library_app

**Run:**

./library_app

### Planned future Improvements

User accounts system

Due dates & fine calculation

GUI using Qt

Database integration

CMake