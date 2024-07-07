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
	static void printAuthors(std::vector<Author*>& vAuthors, bool isWithBooks = false);
	static Author* findAuthor(std::vector<Author*>& vAuthors, const std::string& name);
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
	std::vector <Item*> getItemList()
	{
		return vTakenItems;
	}
	static void printClients(const std::vector <Client*>& vClient, bool isPrintBooks = false);
	static Client* find(const std::string& name, std::vector <Client*>& vClient);
	static Client* find(size_t cardNum, std::vector <Client*>& vClient);
	void takeItem(Item* item);


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
	int getAvailableCount()
	{
		return availableCount;
	}
	void give()
	{
		availableCount--;
	}
	void takeBack()
	{
		availableCount++;
	}


	virtual void print() const = 0; 
	static Item* find(const std::string& name, std::vector <Item*>& vItems);
	static Item* find(int year, std::vector <Item*>& vItems);
	

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
	static Book* find(const std::string& name, std::vector <Item*>& vItems);
	static Book* find(int year, std::vector <Item*>& vItems);

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
	static Journal* find(const std::string& name, std::vector <Item*>& vItems);
	static Journal* find(int year, std::vector <Item*>& vItems);

};



