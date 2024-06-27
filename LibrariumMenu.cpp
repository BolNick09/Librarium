#pragma once
#include "LibrariumMenu.h"

#include <conio.h>


void Menu::fillVMenuItems()
{
	vPtrMenuItems.push_back(new MenuItem("\t1. ���������� �������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t1.1. �������� �����", Tasks::BOOK_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t1.2. ����� �����", Tasks::BOOK_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t1.3. ������ ���� ����", Tasks::BOOK_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t2. ���������� ���������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t2.1. �������� ������", Tasks::JOURNAL_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t2.2. ����� �������", Tasks::JOURNAL_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t2.3. ������ ���� ��������", Tasks::JOURNAL_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t3. ���������� ��������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t3.1. �������� ������", Tasks::AUTHOR_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t3.2. ������ ���� �������", Tasks::AUTHOR_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t4. ���������� ����������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t4.1. �������� ��������", Tasks::CLIENT_ADD));
	vPtrMenuItems.push_back(new MenuItem("\t4.2. ����� ��������", Tasks::CLIENT_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t4.3. ������ ���� ���������", Tasks::CLIENT_LIST));
	vPtrMenuItems.push_back(new MenuItem("\t5. ������ ��������� ���������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t5.1. ������ �������", Tasks::ITEM_GIVE));
	vPtrMenuItems.push_back(new MenuItem("\t6. ������� ��������� �� ���������", Tasks::TITLE));
	vPtrMenuItems.push_back(new MenuItem("\t6.1. ������� �������", Tasks::ITEM_TAKE_BACK));
	vPtrMenuItems.push_back(new MenuItem("\t7. ����� ����� �� ������ � ��������", Tasks::ITEM_SEARCH));
	vPtrMenuItems.push_back(new MenuItem("\t7.1. ����� �� ���� ������", Tasks::ITEM_SEARCH_YEAR));
	vPtrMenuItems.push_back(new MenuItem("\t8. �������� ������", Tasks::ITEM_LOAD_FILE));
	vPtrMenuItems.push_back(new MenuItem("\t9. �����", Tasks::EXIT));
}

void Menu::printMenu() const
{
	for (auto i : vPtrMenuItems)
	{
		if (i->isSelected())
			std::cout << "-->"; 
		
		std::cout << i->getName() << std::endl;	
	}

}
int Menu::findSelected()
{
	for (size_t i = 0; i < vPtrMenuItems.size(); i++)
	{
		if (vPtrMenuItems[i]->isSelected())
			return i;
	}
	return 0;
}

void Menu::navigate(const char key)
{
	system("cls");
	size_t selectedItem = Menu::findSelected();

	if (!selectedItem)
		vPtrMenuItems[0]->switchSelect(true);

	switch (key)
	{
		    case 72: // ������� �� �������� �����
            {
				if (selectedItem > 0)
				{
					vPtrMenuItems[selectedItem]->switchSelect(false);
					selectedItem--;
					vPtrMenuItems[selectedItem]->switchSelect(true);
				}
                break;
            }
            case 80: // ������� �� �������� ����
            {
				if (selectedItem < vPtrMenuItems.size() - 1)
				{
					vPtrMenuItems[selectedItem]->switchSelect(false);
					selectedItem++;
					vPtrMenuItems[selectedItem]->switchSelect(true);
				}
                break;
            }
			case 13: //ENTER
			{
				vPtrMenuItems[selectedItem]->execTask();
				break;
			}
		default:
		{
			break;
		}
	}
	Menu::printMenu();



}

void MenuItem::execTask()
{
	system("cls");
	
	switch (task)
	{
		case TITLE :
		{
			std::cout << "TITLE" << std::endl; //������������ �����
			break;
		}
		case BOOK_ADD :
		{
			std::cout << "BOOK_ADD" << std::endl;			//�������� �����
			break;
		}
		case BOOK_SEARCH :
		{
			std::cout << "BOOK_SEARCH" << std::endl;	//����� �����
			break;
		}
		case BOOK_LIST :
		{
			std::cout << "BOOK_LIST" << std::endl;	//������ ���� ����
			break;
		}
		case JOURNAL_ADD :
		{
			std::cout << "JOURNAL_ADD" << std::endl;	//�������� ������
			break;
		}
		case JOURNAL_SEARCH :
		{
			std::cout << "JOURNAL_SEARCH" << std::endl;	//����� �������
			break;
		}
		case JOURNAL_LIST:
		{
			std::cout << "JOURNAL_LIST" << std::endl;	//������ ���� ��������
			break;
		}
		case AUTHOR_ADD :
		{
			
			std::cout << "������� ������� ���������� ������" << std::endl;	//�������� ������
			std::cout << "������� ���: ";
			std::string name;
			std::cin >> name;
			std::cout << std::endl << "������� ��� ��������: ";
			int age;
			std::cin >> age;
			Author author(name, age);
			author.addAuthor(vAuthors, author);
			std::cout << std::endl << "����� " << name << "������� ��������." << std::endl << "������� ����� �������, ����� ��������� � ����";
			char k = _getch();

			break;
		}
		case AUTHOR_LIST :
		{
			std::cout << "AUTHOR_LIST" << std::endl;	//������ ���� �������
			break;
		}
		case CLIENT_ADD :
		{
			std::cout << "CLIENT_ADD" << std::endl;	//�������� ��������
			break;
		}
		case CLIENT_SEARCH :
		{
			std::cout << "CLIENT_SEARCH" << std::endl;	//����� ��������
			break;
		}
		case CLIENT_LIST :
		{
			std::cout << "CLIENT_LIST" << std::endl;	//������ ���� ���������
			break;
		}
		case ITEM_TAKE_BACK :
		{
			std::cout << "ITEM_TAKE_BACK" << std::endl;	//������� �������
			break;
		}
		case ITEM_GIVE:
		{
			std::cout << "ITEM_GIVE" << std::endl;	//������ �������
			break;
		}
		case ITEM_SEARCH :
		{
			std::cout << "ITEM_SEARCH" << std::endl;	//����� ����� �� ������ � ��������	
			break;
		}
		case ITEM_SEARCH_YEAR :
		{
			std::cout << "ITEM_SEARCH_YEAR" << std::endl;	//����� �� ���� ������
			break;
		}
		case ITEM_LOAD_FILE :
		{
			std::cout << "ITEM_LOAD_FILE" << std::endl;	//�������� ������
			break;
		}
		case EXIT :
		{
			std::cout << "EXIT" << std::endl;	//�����
			break;
		}
		
	}
}

