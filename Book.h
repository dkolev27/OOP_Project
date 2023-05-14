#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
    // Constructors
	Book(const string& author = "", const string& title = "", const string& genre = "", const string& short_discription = "", unsigned year = 0, const string& keywords = "", float rating = 0, int bibliotheque_unique_number = 0);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	void input(); 
	void print();

	friend std::istream& operator>>(std::istream& in, Book& book); 
	friend std::ostream& operator<<(std::ostream& out, Book& book); 

    // Setters and Getters
	void setAuthor(const string& author);
	string getAuthor() const;
	void setTitle(const string& title);
	string getTitle() const;
	void setGenre(const string& genre);
	string getGenre() const;
	void setShortDiscription(const string& short_discription);
	string getShortDiscription() const;
	void setYear(unsigned year);
	unsigned getYear() const;
	void setKeywords(const string& keywords);
	string getKeywords() const;
	void setRating(float rating);
	float getRating() const;
	void setBibliothequeUniqueNumber(int bibliotheque_unique_number);
	int getBibliothequeUniqueNumber() const;

private:
    // Fields
	string author;
	string title;
	string genre;
	string short_discription;
	unsigned year;
	string keywords;
	float rating;
	int bibliotheque_unique_number;

    // Helpers
	void clear();
	void copy(const Book& other);
};

bool booksYearCmp(const Book* a, const Book* b);
bool booksAuthorCmp(const Book* a, const Book* b);
bool booksTitleCmp(const Book* a, const Book* b);
bool booksRatingCmp(const Book* a, const Book* b);