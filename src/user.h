#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
	std::string name;
	std::vector<std::string> borrowedBooks;

	User(std::string n);

	void borrowBook(const std::string& title);
	void returnBook(const std::string& title);
};

#endif