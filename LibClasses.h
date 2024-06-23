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

};

class Client
{
private:
	std::string firstName;
	std::string sureName;
	size_t cardNum;
	std::vector <Item*> vTakenItems;

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



