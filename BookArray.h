#pragma once
#include "Book.h"
#include <string>
#include <vector>

using namespace std;

class BookArray
{
public:
    // Constructors
	BookArray();
	BookArray(const BookArray& other);
	BookArray& operator=(const BookArray& other);
	~BookArray();

    // Methods
	void addBook(const Book& book);
	void openFile(const string& filepath);
	void saveFile(const string& filepath);
	void saveFile();
	void printAll() const;
	void printView() const;
	Book* getByISBN(int isbn) const;
	Book* getByTitle(const string& title) const;
	Book* getByAuthor(const string& author) const;
	Book* getByTag(const string& tag) const;
	bool removeByISBN(int isbn);
	void booksSort(bool (*cmpFunction)(const Book* a, const Book* b), bool desc = false);
	void close();

	string getFilepath() const;
	int getCount() const;
	void setFilepath(const string& filepath);
	 
private:
    // Fields
	vector<Book*> books;
	string filepath;

    // Helpers
	void copy(const BookArray& other);
	void clear();
};

