#ifndef BOOK_FACTORY_H
#define BOOK_FACTORY_H

#include "Book.h"
#include <string>

class BookFactory {
public:
    static Book createBook(const std::string& title, const std::string& author);
};

#endif