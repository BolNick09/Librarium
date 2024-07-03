#include "LibClasses.h"

#include <algorithm>
#include <iostream>


void Author::printAuthors(std::vector<Author*>& vAuthors)
{
    //std::sort(vAuthors.begin(), vAuthors.end(), [](Author a, Author b) { return a.name < b.name; });

    for (Author* author : vAuthors)
    {
        std::cout << "Name: " << author->name << " Date of birth: " << author->dateOfBirth << " Num of books: " << author->vOwnItems.size() << std::endl;
        if (author->vOwnItems.size())
        {
            std::cout << "������ ���� ������: " << std::endl;
            for (Item* item : author->vOwnItems)            
                item->print();            
        }
    }

}

Author* Author::findAuthor(std::vector<Author*>& vAuthors, std::string name)
{
    for (Author* author : vAuthors) 
    {
        if (author->name == name)
            return author;
        
    }
    std::cout << "����� �� ������" << std::endl;
    return nullptr;
}

void Client::printClients(const std::vector <Client*>& vClient) 
{
    for (Client* client : vClient)
        client->print();
    
}

Client* Client::find(const std::string& name, std::vector <Client*>& vClient)
{
    std::cout << "������ ����� �� ����� ��� �������" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->firstName == name)
            return client;
        if (client->sureName == name)
            return client;
        
    }
    std::cout << "������ �� ������" << std::endl;
    return nullptr;
}

Client* Client::find(size_t cardNum, std::vector<Client*>& vClient)
{
    std::cout << "������ ����� �� ������ ������������� ������" << std::endl;
    for (Client* client : vClient) 
    {
        if (client->cardNum == cardNum)
            return client;        
    }
    std::cout << "������ �� ������" << std::endl;
    return nullptr;
}

void Book::print() const
{
    std::cout << "������ �����:" << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  ��������: " << name << std::endl;
    std::cout << "  �����: " << author->getName() << std::endl;
    std::cout << "  ��� ����������: " << publishYear << std::endl;
    std::cout << "  ����� �����: " << totalCount << std::endl;
    std::cout << "  �������� �����������: " << availableCount << std::endl;
    std::cout << "  ISBN: " << ISBN << std::endl;
    std::cout << "  ���������� �������: " << pageCount << std::endl;
}

void Journal::print() const
{
    std::cout << "������ �������:" << std::endl;
    std::cout << "  ID: " << id << std::endl;
    std::cout << "  ��������: " << name << std::endl;
    std::cout << "  �����: " << author->getName() << std::endl;
    std::cout << "  ��� ����������: " << publishYear << std::endl;
    std::cout << "  ����� �����: " << totalCount << std::endl;
    std::cout << "  �������� �����������: " << availableCount << std::endl;
    std::cout << "  ����� ����������: " << pubNum << std::endl;
    std::cout << "  ���������: " << category << std::endl;
}