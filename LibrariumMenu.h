#pragma once

#include <iostream>

#include "LibClasses.h"


enum Tasks
{
	TITLE = -1,			//������������ �����
	BOOK_ADD = 1,		//�������� �����
	BOOK_SEARCH,		//����� �����
	BOOK_LIST,			//������ ���� ����
	JOURNAL_ADD,		//�������� ������
	JOURNAL_SEARCH,		//����� �������
	JOURNAL_LIST,		//������ ���� ��������
	AUTHOR_ADD,			//�������� ������
	AUTHOR_LIST,		//������ ���� �������
	CLIENT_ADD,			//�������� ��������
	CLIENT_SEARCH,		//����� ��������
	CLIENT_LIST,		//������ ���� ���������
	ITEM_GIVE,			//������ �������
	ITEM_TAKE_BACK,		//������� �������
	ITEM_SEARCH,		//����� ����� �� ������ � ��������
	ITEM_SEARCH_YEAR,	//����� �� ���� ������
	ITEM_LOAD_FILE,		//�������� ������
	EXIT				//�����
};

class MenuItem
{
	//����� �������� ����, �������� � ���� ��������, ���� ������ �������� � ID. ���� ����� ������������, ��� ID = -1
private:
	std::string name;
	bool flSelected;
	Tasks task;
public:
	MenuItem(const std::string& name, Tasks task) : name(name), task (task), flSelected(false) {}
	const std::string& getName()
	{
		return name;
	}
	bool isSelected()
	{
		return flSelected;
	}
	size_t getTask()
	{
		return task;
	}
	void switchSelect(bool fl)
	{
		flSelected = fl;
	}
};

class Menu
{
private:
	std::vector <MenuItem*> vPtrMenuItems;

	std::vector<Author*> vAuthors;
	std::vector<Client*> vClients;
	std::vector<Item*> vItems;
public:
	void fillVMenuItems();
	void printMenu() const;

	void navigate(const char key);
	int findSelected();
	void execTask(Tasks task);

	~Menu()
	{
		for (auto a : vAuthors)
			delete a;
		for (auto c : vClients)
			delete c;
		for (auto i : vItems)
			delete i;
		for (auto m : vPtrMenuItems)
			delete m;
		vAuthors.clear();
		vClients.clear();
		vItems.clear();
		vPtrMenuItems.clear();
	}


};
std::string generateISBN();




