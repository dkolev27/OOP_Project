#pragma once
#include <string>

using namespace std;

class User
{
public:
    // Constructors
	User();
	User(const string& username, const string& password, bool isAdmin);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	friend std::istream& operator>>(std::istream& in, User& user);
	friend std::ostream& operator<<(std::ostream& out, User& user);

    // Setters and Getters
	void setUsername(const string& username);
	string getUsername() const;
	void setPassword(const string& password);
	string getPassword() const;
	void setIsAdmin(bool isAdmin);
	bool getIsAdmin() const;

	void print() const;

private:
    // Fields
	string username;
	string password;
	bool isAdmin;

	// Helpers
	void copy(const User& other);
	void clear();
};

