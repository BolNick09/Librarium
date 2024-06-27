#pragma once
#include <string>
#include <vector>
//------------------------------------------

class Item;

class Author
{
private:
	std::string name;
	size_t dateOfBirth;
	std::vector <Item*> vOwnItems;
public:
	Author(std::string name, size_t dateOfBirth) : name(name), dateOfBirth(dateOfBirth) {}
	void addAuthor(std::vector<Author>& vAuthors, Author author);
	void printAuthors(std::vector<Author>& vAuthors);
	Author* findAuthor(std::vector<Author>& vAuthors, std::string name);


};
std::vector <Author> vAuthors;

class Client
{
private:
	std::string firstName;
	std::string sureName;
	size_t cardNum;
	std::vector <Item*> vTakenItems;

};
std::vector <Client> vClients;
//------------------------------------------

class Item
{
private:
	
	size_t id;
	std::string name;
	Author* author;
	size_t publishYear;
	int totalCount;
	int avaliableCount;
};

class Book : public Item
{
private:
	std::string ISBN;
	size_t pageCount;
};

class Journal : public Item
{
private:
	size_t pubNum;
	std::string category;
};
std::vector <Item> vItems;



