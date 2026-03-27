#include "BookFactory.h"

Book BookFactory::createBook(const std::string& title, const std::string& author) {
    return Book(title, author, true);
}