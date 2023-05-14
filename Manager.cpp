#include <iostream>
#include <string>
#include "Manager.h"
#include "Book.h"
#include "BookArray.h"
#include "UserArray.h"

using namespace std;

void Manager::commands()
{
	BookArray books; 
	UserArray users("users.txt");
	User* loggedUser = nullptr;

	do
	{
		string line;
		cout << "> ";
		getline(cin, line);
		vector<string> parts = splitLine(line);
        	string command = parts[0];

		if (parts.size() == 0) continue;

        	if (command == "login")
         	   loggedUser = logInUser(users, loggedUser, parts);

        	else if (command == "logout")
          	   loggedUser = logOutUser(loggedUser, parts);

        	else if (command == "usersAdd")
           	   addUser(users, loggedUser, parts);

        	else if (command == "usersRemove")
            	   removeUser(users, loggedUser, parts);

        	else if (command == "open")
            	   openBooksFile(books, parts);

        	else if (command == "close")
            	   closeBooksFile(books, parts);

        	else if (command == "save")
            	   line = saveBooksFile(books, line, parts);

        	else if (command == "saveAs")
            	   saveBooksFileAs(books, parts);

        	else if (command == "booksAdd")
            	   booksAdd(books, loggedUser, parts);

        	else if (command == "booksAll")
            	   showAllBooks(books, loggedUser, parts);

        	else if (command == "booksView")
            	   booksView(books, loggedUser, parts);

        	else if (command == "booksInfo")
            	   booksInfo(books, loggedUser, parts);

        	else if (command == "booksFind")
            	   booksFind(books, loggedUser, parts);

        	else if (command == "booksRemove")
            	   booksRemove(books, loggedUser, parts);

        	else if (command == "booksSort")
            	   booksSort(books, loggedUser, parts);

        	else if (command == "help")
            	   help(parts);

        	else if (command == "exit")
            	   break;

        	else
            	   cout << "Invalid command!" << endl;

	} 
	while (true);
}

vector<string> Manager::splitLine(string line)
{
	vector<string> vec;
	while (line.size()) 
	{ 
		size_t pos = line.find(' ');
		while (pos == 0)
		{
			line = line.substr(1);
			pos = line.find(' ');
		}
		if (pos == -1)
		{
			if (line.size())
			{
				vec.push_back(line);
				line.clear();
			}
		}
		else
		{
			string part = line.substr(0, pos);
			vec.push_back(part);
			line = line.substr(pos + 1);
		}
	}
	return vec;
}


User *Manager::logInUser(const UserArray &users, User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Too many arguments!" << endl;

    else
    {
        string username;
        string password;

        if (loggedUser)
            cout << "You are already logged in!!!" << endl;

        else
        {
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            User *user = users.logInUser(username, password);

            if (user)
            {
                loggedUser = user;
                cout << "Welcome " << loggedUser->getUsername() << "!" << endl;
            }
            else
                cout << "Invalid username or password!" << endl;
        }
    }
    return loggedUser;
}

void Manager::openBooksFile(BookArray &books, const vector<string> &parts) const
{
    if (parts.size() > 2)
        cout << "Too many arguments!" << endl;

    else if (parts.size() == 2)
        books.openFile(parts[1]);

    else
        cout << "Please input a filename!" << endl;
}

void Manager::closeBooksFile(BookArray &books, const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        books.close();
        cout << "File closed!" << endl;
    }
}

void Manager::removeUser(UserArray &users, const User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 2)
        cout << "Too many arguments!" << endl;

    else if (parts.size() == 2)
    {
        if (loggedUser)
        {
            if (loggedUser->getIsAdmin())
            {
                if (parts[1] == loggedUser->getUsername())
                    cout << "Can't remove yourself!" << endl;

                else
                {
                    bool userRemoved = users.removeUser(parts[1]);
                    if (userRemoved)
                    {
                        users.saveFile();
                        cout << "User removed!" << endl;
                    }
                    else
                        cout << "User doesn't exist!" << endl;
                }
            }
            else
                cout << "Only admin can remove users!!!" << endl;
        }
        else
            cout << "You have to be logged in!" << endl;
    }
    else
        cout << "Please input username and password!" << endl;
}

void Manager::addUser(UserArray &users, const User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 3)
        cout << "Too many arguments!" << endl;

    else if (parts.size() == 3)
    {
        if (loggedUser)
        {
            if (loggedUser->getIsAdmin())
            {
                User* existingUser = users.getUser(parts[1]);
                if (existingUser)
                    cout << "User already exists!" << endl;
                else
                {
                    User newUser(parts[1], parts[2], false);
                    users.addUser(newUser);
                    users.saveFile();
                    cout << "User added!" << endl;
                }
            }
            else
                cout << "Only admin can add users!!!" << endl;
        }
        else
            cout << "You have to be logged in!" << endl;
    }
    else
        cout << "Please input username and password!" << endl;
}

User *Manager::logOutUser(User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Too many arguments!" << endl;

    else
    {
        if (loggedUser)
        {
            cout << "Goodbye " << loggedUser->getUsername() << "!" << endl;
            loggedUser = nullptr;
        }
        else
            cout << "You are not logged in!" << endl;
    }
    return loggedUser;
}

void Manager::showAllBooks(const BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        if (loggedUser)
            books.printAll();
        else
            cout << "You have to be logged in to view books!" << endl;
    }
}

void Manager::help(const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        cout << "login - logs in an user" << endl;
        cout << "logout - logs out an user" << endl;
        cout << "open <FILEPATH> - opens a book file" << endl;
        cout << "close - closes the current book file" << endl;
        cout << "save - saves the current book file" << endl;
        cout << "saveAs <FILEPATH> - saves the current book file in a new location" << endl;
        cout << "booksAdd - adds a new book" << endl;
        cout << "booksRemove <ISBN> - removes a book" << endl;
        cout << "booksAll - displays all books" << endl;
        cout << "booksView - displays detailed information of all books" << endl;
        cout << "booksInfo <ISBN> - displays book" << endl;
        cout << "booksFind <title|author|tag> <SEARCH> - finds a book" << endl;
        cout << "booksSort <title|author|year|rating> [asc|desc] - sort books" << endl;
        cout << "usersAdd <USERNAME> <PASSWORD> - adds a new user" << endl;
        cout << "usersRemove <USERNAME> - removes a user" << endl;
        cout << "help - displays all commands and their capabilities" << endl;
        cout << "exit - closes the program" << endl;
    }
}

void Manager::booksSort(BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (loggedUser)
    {
        if (books.getCount())
        {
            if (parts.size() > 3)
                cout << "Too many arguments!" << endl;

            else if (parts.size() >= 2)
            {
                bool (*cmpFunction)(const Book * a, const Book * b) = nullptr;
                if (parts[1] == "title")
                    cmpFunction = booksTitleCmp;

                else if (parts[1] == "author")
                    cmpFunction = booksAuthorCmp;

                else if (parts[1] == "year")
                    cmpFunction = booksYearCmp;

                else if (parts[1] == "rating")
                    cmpFunction = booksRatingCmp;

                bool desc = false;
                if (parts.size() >= 3)
                {
                    if (parts[2] == "asc")
                        desc = false;

                    else if (parts[2] == "desc")
                        desc = true;

                    else
                        cmpFunction = nullptr;
                }
                if (cmpFunction)
                {
                    books.booksSort(cmpFunction, desc);
                    cout << "Books sorted!" << endl;
                }
                else
                    cout << "Not a valid sorting method!" << endl;
            }
            else
                cout << "Please choose sorting method!" << endl;
        }
        else
            cout << "No books to be sorted!" << endl;
    }
    else
        cout << "You have to be logged in to sort books!" << endl;
}


void Manager::booksRemove(BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (loggedUser && loggedUser->getIsAdmin())
    {

        if (parts.size() >= 2)
        {
            int isbn = atoi(parts[1].c_str());
            bool isRemoved = books.removeByISBN(isbn);
            if (isRemoved)
                cout << "Book removed!" << endl;
            else
                cout << "Book not found!" << endl;
        }
        else
            cout << "Please input an ISBN!" << endl;
    }
    else
        cout << "Only admin can remove books!" << endl;
}

void Manager::booksFind(const BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (loggedUser)
    {
        if (parts.size() >= 3)
        {
            Book* book = nullptr;
            string arg = parts[2];
            bool error = false;

            for (size_t i = 3; i < parts.size(); i++)
                arg += " " + parts[i];

            if (parts[1] == "title")
                book = books.getByTitle(arg);

            else if (parts[1] == "author")
                book = books.getByAuthor(arg);

            else if (parts[1] == "tag")
                book = books.getByTag(arg);

            else
            {
                error = true;
                cout << "Invalid search criteria!" << endl;
            }

            if (!error)
            {
                if (book)
                    book->print();
                else
                    cout << "Book not found!" << endl;
            }
        }
        else
            cout << "Not enough arguments!" << endl;
    }
    else
        cout << "You have to be logged in to find books!" << endl;
}

void Manager::booksInfo(const BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (loggedUser)
    {
        if (parts.size() > 2)
            cout << "Too many arguments!" << endl;

        else if (parts.size() == 2)
        {
            int isbn = atoi(parts[1].c_str());
            Book* book = books.getByISBN(isbn);

            if (book)
                cout << *book;
            else
                cout << "Book not found!" << endl;
        }
        else
            cout << "Please input a ISBN!" << endl;
    }
    else
        cout << "You have to be logged in to view books!" << endl;
}

void Manager::booksView(const BookArray &books, const User *loggedUser, const vector<string> &parts) const
{
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        if (loggedUser)
            books.printView();

        else
            cout << "You have to be logged in to view books!" << endl;
    }
}

void Manager::booksAdd(BookArray &books, const User *loggedUser, const vector<string> &parts) const {
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        if (loggedUser && loggedUser->getIsAdmin())
        {
            Book book;
            book.input();
            books.addBook(book);
        }
        else
            cout << "Only admin can add new books!" << endl;
    }
}

void Manager::saveBooksFileAs(BookArray &books, const vector<string> &parts) const {
    if (parts.size() > 2)
        cout << "Too many arguments!" << endl;

    else if (parts.size() == 2)
        books.saveFile(parts[1]);

    else
        cout << "Please input a filename!" << endl;
}

string &Manager::saveBooksFile(BookArray &books, string &line, const vector<string> &parts) const {
    if (parts.size() > 1)
        cout << "Invalid command!" << endl;

    else
    {
        if (books.getFilepath().size())
            books.saveFile();

        else
        {
            cout << "Filename: ";
            getline(cin, line);
            books.saveFile(line);
        }
    }
    return line;
}
