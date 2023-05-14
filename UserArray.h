#pragma once
#include "User.h"
#include <string>
#include <vector>

using namespace std;

class UserArray
{
public:
    // Constructors
	UserArray(const string& filepath);
	UserArray(const UserArray& other);
	UserArray& operator=(const UserArray& other);
	~UserArray();

    // Methods
	void addUser(const User& user);
	void openFile(const string& filepath);
	void saveFile() const;
	User* logInUser(const string& username, const string& password) const;
	User* getUser(const string& username) const;
	bool removeUser(const string& username);

	void print() const;

private:
    // Fields
	vector<User*> users;
	string filepath;

	// Helpers
	void copy(const UserArray& other);
	void clear();
};
