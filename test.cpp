#pragma once
#include <string>
#include <vector>
#include <ctime>

class Author {
public:
    std::string name;
    Author(const std::string& n) : name(n) {}
};

class Book {
public:
    std::string title;
    Author* author;
    std::string isbn;

    Book(const std::string& t, Author* a, const std::string& i)
        : title(t), author(a), isbn(i) {}
};

class User {
private:
    std::string name;
    std::string email;

public:
    User(const std::string& n, const std::string& e) : name(n), email(e) {}

    std::string getName() { return name; }
    std::string getEmail() { return email; }
};

class Loan {
public:
    Book* book;
    User* user;
    std::time_t dueDate;

    Loan(Book* b, User* u, std::time_t due) : book(b), user(u), dueDate(due) {}

    bool isOverdue() {
        return std::time(nullptr) > dueDate;
    }
};

class Library {
public:
    std::vector<Book*> books;
    std::vector<User*> users;
    std::vector<Loan*> loans;

    void addBook(Book* b) {
        books.push_back(b);
    }

    void registerUser(User* u) {
        users.push_back(u);
    }

    void issueLoan(Book* b, User* u, std::time_t due) {
        loans.push_back(new Loan(b, u, due));
    }
};
