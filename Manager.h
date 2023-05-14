#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "UserArray.h"
#include "BookArray.h"

using namespace std;

struct Manager
{
	void commands();

    vector <string> splitLine(string line);

    // Functions used in commands()
    User *logInUser(const UserArray &users, User *loggedUser, const vector<string> &parts) const;
    User *logOutUser(User *loggedUser, const vector<string> &parts) const;
    string &saveBooksFile(BookArray &books, string &line, const vector<string> &parts) const;
    void saveBooksFileAs(BookArray &books, const vector<string> &parts) const;
    void addUser(UserArray &users, const User *loggedUser, const vector<string> &parts) const;
    void removeUser(UserArray &users, const User *loggedUser, const vector<string> &parts) const;
    void openBooksFile(BookArray &books, const vector<string> &parts) const;
    void closeBooksFile(BookArray &books, const vector<string> &parts) const;
    void booksAdd(BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void booksView(const BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void booksInfo(const BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void booksFind(const BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void booksRemove(BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void booksSort(BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void showAllBooks(const BookArray &books, const User *loggedUser, const vector<string> &parts) const;
    void help(const vector<string> &parts) const;
};

