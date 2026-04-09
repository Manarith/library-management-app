# library-management-app
A simple console-based Library Management System built in C++. It demonstrates programming concepts like Object-Oriented Programming (OOP), file handling, basic data management and design patterns.

## Prerequisites

- C++17 compatible compiler (g++, clang, MSVC)

- CMake >= 3.10

### Features

**Book Management**

- Add new books (title & author)

- View all books in the library

- Search books by keyword

**Borrowing System**

- Borrow available books

- Return borrowed books

- Track availability status

**File Persistence (data/books.txt)**

- Automatically loads books from file on startup

- Saves all changes to file on exit

- Data persists between program runs

**Build & Run (CMake)**

1. Open terminal in project root:

bash

cd build

cmake ..

cmake --build . --config Debug

2. Run the program:

**Linux/macOS**

./library_app

**Windows**

Debug\library_app.exe

### Planned future Improvements

- User accounts system

- Due dates & fine calculation

- GUI using Qt

- Database integration