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
	static void printAuthors(std::vector<Author>& vAuthors);
	Author* findAuthor(std::vector<Author>& vAuthors, std::string name);
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
	static void printClients(const std::vector <Client>& vClient);
	static Client* find(const std::string& Name, std::vector <Client>& vClient);
	static Client* find(size_t cardNum, std::vector <Client>& vClient);


};
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



