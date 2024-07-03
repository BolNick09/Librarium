#include "LibrariumMenu.h"

#include <conio.h>
#include <random>



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
				Menu::execTask(static_cast <Tasks> (vPtrMenuItems[selectedItem]->getTask()));
				break;
			}
		default:
		{
			break;
		}
	}
	Menu::printMenu();



}

void Menu::execTask(Tasks task)
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
			std::cout << "������� ������� ���������� �����" << std::endl;			//�������� �����
			if (!vAuthors.size())
			{
				std::cout << "�� ������� �� ������ ������" << std::endl;
				std::cout << "������� ������ ENTER, ����� ��������� � ����" << std::endl;

				char k = _getch();
				system("cls");
				break;
			}

			std::cout << "������� ������ ��� ������, ������ ������� �������� ����: " << std::endl;
			Author::printAuthors(vAuthors);
			std::string authorName;
			std::getline(std::cin, authorName);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Author* author = Author::findAuthor(vAuthors, authorName);
			if (!author)
			{
				std::cout << "������� ������ ENTER, ����� ��������� � ����" << std::endl;

				char k = _getch();				
				system("cls");
				break;
			}
			std::cout << "������� �������� �����: ";
			std::string bookName;
			std::getline(std::cin, bookName);
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "������� ��� �������: ";
			size_t year;
			std::cin >> year;
			std::cout << std::endl;

			std::cout << "������� ���������� �������: ";
			size_t pageCount;
			std::cin >> pageCount;
			std::cout << std::endl;

			std::cout << "������� ���������� ����: ";
			size_t bookCount;
			std::cin >> bookCount;
			std::cout << std::endl;
			Book* book = new Book(bookCount * pageCount * rand() % 1000, bookName, author, year, bookCount, bookCount, generateISBN(), pageCount);
			author->attachItem(book);
			vItems.push_back(std::move (book));

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "������� ������ ENTER, ����� ��������� � ����" << std::endl;

			char k = _getch();
			system("cls");

			break;
		}
		case BOOK_SEARCH :
		{
			std::cout << "BOOK_SEARCH" << std::endl;	//����� �����
			break;
		}
		case BOOK_LIST :
		{
			std::cout << "������� ������� ������ ������ ���� ����" << std::endl;	//������ ���� ����
			for (Item* item : vItems) 
			{				
				if (dynamic_cast<Book*>(item)) 
					static_cast<Book*>(item)->print();				
			}
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

			std::cout << "������� ���: (���������) ";
			std::string name;
			std::getline(std::cin, name);
			std::cout << std::endl << "������� ��� ��������: ";
			int age;
			std::cin >> age;
			vAuthors.push_back (new Author (name, age));
			std::cout << std::endl << "����� " << name << "������� ��������." << std::endl << "������� ������� ENTER, ����� ��������� � ����";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������ ������ �����
			char k = _getch();
			system("cls");

			break;
		}
		case AUTHOR_LIST :
		{
			
			std::cout << "������� ������� ������ ������ �������" << std::endl;	//������ ���� �������
			Author::printAuthors(vAuthors);
			std::cout << "������� ENTER ��� �������� � ����" << std::endl;
			char c = _getch();
			break;
		}
		case CLIENT_ADD :
		{
			std::cout << "������� ������� ���������� ��������" << std::endl;	//�������� ��������

			std::cout << "������� ���: (���������) ";
			std::string firstName;
			std::getline(std::cin, firstName);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������ ������ �����

			std::cout << "������� �������: (���������) ";
			std::string sureName;
			std::getline(std::cin, sureName);

			int cardNum;
			std::cout << "������������ ��������� ������ ������������� ������" << std::endl;
			do  //��������� ����������� ������ ������������� ������
			{
				cardNum = rand() % 10000;
			} 
			while (Client::find(cardNum, vClients));

			vClients.push_back(new Client(firstName, sureName, cardNum));
			std::cout << std::endl << "�������� " << firstName << " " << sureName << " ������������ ����� #" << cardNum << " ������� ��������." << std::endl 
				      << "������� ������ ENTER, ����� ��������� � ����";
			
			char k = _getch();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//������ ������ �����
			system("cls");
			break;
		}
		case CLIENT_SEARCH :
		{
			std::cout << "������� ������� ������ ���������" << std::endl;	//����� ��������
			std::cout << "����� �� ����� ��� ������ ������������� ������? (0 - ���, 1 - �����)" << std::endl;
			bool isCard;
			std::cin >> isCard;
			if (!isCard)
			{
				std::cout << "������� ��� ��� �������: ";
				std::string name;
				std::cin >> name;
				Client* fClient = Client::find(name, vClients);
				if (fClient)
				{
					std::cout << "�������� ������" << std::endl;
					fClient->print();
				}
			}
			else
			{
				std::cout << "������� ����� ������������� ������: ";
				size_t cardNum;
				std::cin >> cardNum;
				Client* fClient = Client::find(cardNum, vClients);
				if (fClient)
				{
					std::cout << "�������� ������" << std::endl;
					fClient->print();
				}
			}
			std::cout << "������� ENTER ��� �������� � ����" << std::endl;
			char c = _getch();
			break;
		}
		case CLIENT_LIST :
		{
			std::cout << "������� ������� ������ ������ ���������" << std::endl;	//������ ���� ���������
			Client::printClients(vClients);
			std::cout << "������� ENTER ��� �������� � ����" << std::endl;
			char c = _getch();
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




std::string generateISBN() 
{
	std::random_device rd;
	std::mt19937 gen(rd());

	std::string isbn;
	for (int i = 0; i < 9; i++) 
		isbn += std::to_string(gen() % 10);
	

	int sum = 0;
	for (int i = 0; i < 9; i++) 
		sum += (i + 1) * (isbn[i] - '0');
	
	int checkDigit = (11 - sum % 11) % 11;

	// ��������� ����������� ����� � ISBN
	isbn += std::to_string(checkDigit);

	return isbn;
}

