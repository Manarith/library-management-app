cmake_minimum_required(VERSION 3.10)

project(LibraryApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(library_app
    src/main.cpp
    src/Library.cpp
    src/BookFactory.cpp
    src/User.cpp
)