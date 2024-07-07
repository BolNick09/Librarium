#include "LibClasses.h"

#include <algorithm>
#include <iostream>


void Author::printAuthors(std::vector<Author*>& vAuthors, bool isWithBooks)
{
    //std::sort(vAuthors.begin(), vAuthors.end(), [](Author a, Author b) { return a.name < b.name; });

    for (Author* author : vAuthors)
    {
        std::cout << "Name: " << author->name << " Date of birth: " << author->dateOfBirth << " Num of books: " << author->vOwnItems.size() << std::endl;
        if (author->vOwnItems.size() && isWithBooks)
        {
            std::cout << "������ ���� ������: " << std::endl;
            for (Item* item : author->vOwnItems)            
                item->print();            
        }
    }

}

Author* Author::findAuthor(std::vector<Author*>& vAuthors, const std::string& name)
{
    for (Author* author : vAuthors) 
    {
        if (author->name == name)
            return author;
        
    }
    //std::cout << "����� �� ������" << std::endl;
    return nullptr;
}

void Client::printClients(const std::vector <Client*>& vClient, bool isPrintBooks) 
{
    for (Client* client : vClient)
    {
        client->print();
        if (isPrintBooks)
        {
            if (client->vTakenItems.size())
            {
                for (auto item : client->vTakenItems)
                    item->print();
            }
        }
    }
    
}

Client* Client::find(const std::string& name, std::vector <Client*>& vClient)
{
    //std::cout << "������ ����� �� ����� ��� �������" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->firstName == name)
            return client;
        if (client->sureName == name)
            return client;
        
    }
    //std::cout << "������ �� ������" << std::endl;
    return nullptr;
}

Client* Client::find(size_t cardNum, std::vector<Client*>& vClient)
{
    //std::cout << "������ ����� �� ������ ������������� ������" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->cardNum == cardNum)
            return client;        
    }
    //std::cout << "������ �� ������" << std::endl;
    return nullptr;
}

void Client::takeItem(Item* item)
{
    if (item->getAvailableCount())
    {
        vTakenItems.push_back(item);
        item->give();
    }
    else
        std::cout << "� ���������� ����������� ��� �����" << std::endl;
}

void Client::giveBackItem(Item* item)
{
    for (size_t i = 0; i < vTakenItems.size(); i++) 
    {
        if (vTakenItems[i] == item) 
        {
            vTakenItems.erase(vTakenItems.begin() + i);
            item->takeBack();
            return;
        }
    }
    std::cout << "� �������� ��� ����� �����" << std::endl;
    return;
    
}

void Book::print() const
{
    std::cout << "  ������ �����: " << name << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  �����: " << author->getName() << std::endl;
    std::cout << "  ��� ����������: " << publishYear << std::endl;
    std::cout << "  ����� �����: " << totalCount << std::endl;
    std::cout << "  �������� �����������: " << availableCount << std::endl;
    std::cout << "  ISBN: " << ISBN << std::endl;
    std::cout << "  ���������� �������: " << pageCount << std::endl;
}

Item* Item::find(const std::string& name, std::vector<Item*>& vItems)
{
    for (Item* item : vItems) 
    {
        if (item->name == name) 
            return item;       
    }
    return nullptr;  
}

Item* Item::find(int year, std::vector<Item*>& vItems)
{
    for (Item* item : vItems)
    {
        if (item->publishYear == year)
            return item;
    }
    return nullptr;
}


Book* Book::find(int year, std::vector <Item*>& vItems)
{
    Item* item = Item::find(year, vItems);
    if (item && dynamic_cast<Book*>(item)) 
        return dynamic_cast<Book*>(item);
    
    return nullptr;  // ������ �� �������
}

Book* Book::find(const std::string& name, std::vector <Item*>& vItems)
{
    Item* item = Item::find(name, vItems);
    if (item && dynamic_cast<Book*>(item))
        return dynamic_cast<Book*>(item);

    return nullptr;  // ������ �� �������
}

Journal* Journal::find(int year, std::vector <Item*>& vItems)
{
    Item* item = Item::find(year, vItems);
    if (item && dynamic_cast<Journal*>(item) )
        return dynamic_cast<Journal*>(item);

    return nullptr;  // ������ �� �������
}

Journal* Journal::find(const std::string& name, std::vector <Item*>& vItems)
{
    Item* item = Item::find(name, vItems);
    if (item && dynamic_cast<Journal*>(item))
        return dynamic_cast<Journal*>(item);

    return nullptr;  // ������ �� �������
}

void Journal::print() const
{
    std::cout << "������ �������: " << name << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  �����: " << author->getName() << std::endl;
    std::cout << "  ��� ����������: " << publishYear << std::endl;
    std::cout << "  ����� �����: " << totalCount << std::endl;
    std::cout << "  �������� �����������: " << availableCount << std::endl;
    std::cout << "  ����� ����������: " << pubNum << std::endl;
    std::cout << "  ���������: " << category << std::endl;
}


