#include <iostream>
#include <fstream>
#include "UserArray.h"

using namespace std;

UserArray::UserArray(const string& filepath)
{
	this->filepath = filepath;
	openFile(filepath);

	if (users.size() == 0)
	{
		User admin("admin", "i<3c++", true);
		addUser(admin);
		saveFile();
	}
}

UserArray::UserArray(const UserArray& other)
{
	copy(other);
}

UserArray& UserArray::operator=(const UserArray& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

UserArray::~UserArray()
{
	clear();
}

void UserArray::addUser(const User& user)
{
	users.push_back(new User(user));
}

void UserArray::openFile(const string& filepath)
{
	ifstream file(filepath);
	if (file)
	{
		clear();
		this->filepath = filepath;
		while (!file.eof())
		{
			User user;
			file >> user;

			if (user.getUsername().size() == 0)
				break;

			addUser(user);
		}

		file.close();
	}
}

User* UserArray::logInUser(const string& username, const string& password) const
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if ((users[i]->getUsername() == username) && (users[i]->getPassword() == password))
		    return users[i];
	}
	return nullptr;
}

User* UserArray::getUser(const string& username) const
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if ((users[i]->getUsername() == username))
			return users[i];
	}
	return nullptr;
}

bool UserArray::removeUser(const string& username)
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if ((users[i]->getUsername() == username))
		{
			delete users[i];
			users.erase(users.begin() + i);
			return true;
		}
	}
	return false;
}

void UserArray::saveFile() const
{
	ofstream file(filepath);
	if (file)
	{
		for (size_t i = 0; i < users.size(); i++)
			file << *users[i];

		file.close();
	}
}

void UserArray::print() const
{
	for (size_t i = 0; i < users.size(); i++)
		cout << *users[i];
}

void UserArray::copy(const UserArray& other)
{
	for (size_t i = 0; i < users.size(); i++)
		users.push_back(new User(*other.users[i]));
}

void UserArray::clear()
{
	for (size_t i = 0; i < users.size(); i++)
		delete users[i];

	users.clear();
}