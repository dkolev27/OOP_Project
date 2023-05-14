#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

Book::Book(const string& author, const string& title, const string& genre, const string& short_discription, unsigned year, const string& keywords, float rating, int bibliotheque_unique_number)
{
	this->author = author;
	this->title = title;
	this->genre = genre;
	this->short_discription = short_discription;
	this->year = year;
	this->keywords = keywords;
	this->rating = rating;
	this->bibliotheque_unique_number = bibliotheque_unique_number;
}

Book::Book(const Book& other)
{
	copy(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Book::~Book()
{
	clear();
}

void Book::input()
{
	string line;

	cout << "Enter the author of the book: ";
	getline(cin, line);
	setAuthor(line);

	cout << "Enter the title of the book: ";
	getline(cin, line);
	setTitle(line);

	cout << "Enter the genre of the book: ";
	getline(cin, line);
	setGenre(line);

	cout << "Enter a short discription about the book: ";
	getline(cin, line);
	setShortDiscription(line);

	int year;
	cout << "When was the book published? ";
	cin >> year;
	setYear(year);
	getline(cin, line);

	cout << "Enter some keywords related to the book: ";
	getline(cin, line);
	setKeywords(line);
	
	float rating;
	cout << "Enter the rating of the book: ";
	cin >> rating;
	setRating(rating);
	getline(cin, line);

	int bibliotheque_unique_number;
	cout << "Enter the unique bibliotheque number: ";
	cin >> bibliotheque_unique_number;
	setBibliothequeUniqueNumber(bibliotheque_unique_number);
	getline(cin, line);
}

void Book::print()
{
	if (author.size())
		cout << title << " - " << author << " - " << genre << " - " << bibliotheque_unique_number << endl;
	else
		cout << "NO BOOK!" << endl;
}

void Book::setAuthor(const string& author)
{
	this->author = author;
}

string Book::getAuthor() const
{
	return author;
}

void Book::setTitle(const string& title)
{
	this->title = title;
}

string Book::getTitle() const
{
	return title;
}

void Book::setGenre(const string& genre)
{
	this->genre = genre;
}

string Book::getGenre() const
{
	return genre;
}

void Book::setShortDiscription(const string& short_discription)
{
	this->short_discription = short_discription;
}

string Book::getShortDiscription() const
{
	return short_discription;
}

void Book::setYear(unsigned year)
{
	this->year = year;
}

unsigned Book::getYear() const
{
	return year;
}

void Book::setKeywords(const string& keywords)
{
	this->keywords = keywords;
}

string Book::getKeywords() const
{
	return keywords;
}

void Book::setRating(float rating)
{
	this->rating = rating;
}

float Book::getRating() const
{
	return rating;
}

void Book::setBibliothequeUniqueNumber(int bibliotheque_unique_number)
{
	this->bibliotheque_unique_number = bibliotheque_unique_number;
}

int Book::getBibliothequeUniqueNumber() const
{
	return bibliotheque_unique_number;
}

void Book::clear()
{
	author.clear();
	title.clear();
	genre.clear();
	short_discription.clear();	
	keywords.clear();
}

void Book::copy(const Book& other)
{
	this->author = other.author;
	this->title = other.title;
	this->genre = other.genre;
	this->short_discription = other.short_discription;
	this->year = other.year;
	this->keywords = other.keywords;
	this->rating = other.rating;
	this->bibliotheque_unique_number = other.bibliotheque_unique_number;
}

istream& operator>>(istream& in, Book& book)
{
	string line;

	do
	{
		getline(in, line);
		if (in.eof())
			return in;

	} while (line.size() == 0);

	book.setAuthor(line);

	getline(in, line);
	book.setTitle(line);

	getline(in, line);
	book.setGenre(line);

	getline(in, line);
	book.setShortDiscription(line);

	int year;
	in >> year;
	book.setYear(year);
	getline(in, line);

	getline(in, line);
	book.setKeywords(line);

	float rating;
	in >> rating;
	book.setRating(rating);
	getline(in, line);

	int bibliotheque_unique_number;
	in >> bibliotheque_unique_number;
	book.setBibliothequeUniqueNumber(bibliotheque_unique_number);
	getline(in, line);

	return in;
}

ostream& operator<<(ostream& out, Book& book)
{
	out
		<< book.author << endl
		<< book.title << endl
		<< book.genre << endl
		<< book.short_discription << endl
		<< book.year << endl
		<< book.keywords << endl
		<< book.rating << endl
		<< book.bibliotheque_unique_number << endl;
	 
	return out;
}

bool booksYearCmp(const Book* a, const Book* b)
{
	return a->getYear() > b->getYear();
}

bool booksAuthorCmp(const Book* a, const Book* b)
{
	return a->getAuthor() > b->getAuthor();
}

bool booksTitleCmp(const Book* a, const Book* b)
{
	return a->getTitle() > b->getTitle();
}

bool booksRatingCmp(const Book* a, const Book* b)
{
	return a->getRating() > b->getRating();
}
