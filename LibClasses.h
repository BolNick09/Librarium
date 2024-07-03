#pragma once
#include <string>
#include <vector>
#include <iostream>
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
	static void printAuthors(std::vector<Author*>& vAuthors);
	static Author* findAuthor(std::vector<Author*>& vAuthors, std::string name);
	std::string getName() const
	{
		return name;
	}
	void attachItem(Item* item)
	{
		vOwnItems.push_back(item);
	}
};

class Client
{
private:
	std::string firstName;
	std::string sureName;
	size_t cardNum;
	std::vector <Item*> vTakenItems;
public:
	Client(std::string firstName, std::string sureName, size_t cardNum) : firstName(firstName), sureName(sureName), cardNum(cardNum) {}

	void print()
	{
		std::cout << "Имя: " << firstName << " Фамилия: " << sureName << " Номер читательского билета: " << cardNum << std::endl;
	}
	static void printClients(const std::vector <Client*>& vClient);
	static Client* find(const std::string& Name, std::vector <Client*>& vClient);
	static Client* find(size_t cardNum, std::vector <Client*>& vClient);


};
//------------------------------------------

class Item
{
protected:	
	size_t id;
	std::string name;
	Author* author;
	size_t publishYear;
	int totalCount;
	int availableCount;
public:
	Item(size_t id, std::string name, Author* author, size_t publishYear, int totalCount, int availableCount) :
		id(id),
		name(name),
		author(author),
		publishYear(publishYear),
		totalCount(totalCount),
		availableCount(availableCount)
	{}

	virtual void print() const = 0; 
	

};

class Book : public Item
{
private:
	std::string ISBN;
	size_t pageCount;
public:
	Book(size_t id, std::string name, Author* author, size_t publishYear, int totalCount, int availableCount,
		std::string ISBN, size_t pageCount) :
		Item(id, name, author, publishYear, totalCount, availableCount),
		ISBN(ISBN),
		pageCount(pageCount)
	{}
	void print() const override;

};

class Journal : public Item
{
private:
	size_t pubNum;
	std::string category;
public:
	Journal(size_t id, std::string name, Author* author, size_t publishYear, int totalCount, int availableCount,
		size_t pubNum, std::string category) :
		Item(id, name, author, publishYear, totalCount, availableCount),
		pubNum(pubNum),
		category(category)
	{}
	void print() const override;

};



