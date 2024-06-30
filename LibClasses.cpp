#include "LibClasses.h"

#include <algorithm>
#include <iostream>


void Author::printAuthors(std::vector<Author>& vAuthors)
{
    std::sort(vAuthors.begin(), vAuthors.end(), [](Author a, Author b) { return a.name < b.name; });

        for (Author author : vAuthors)         
            std::cout << "Name: " << author.name << " Date of birth: " << author.dateOfBirth << " Num of books: " << author.vOwnItems.size() << std::endl;        

}

Author* Author::findAuthor(std::vector<Author>& vAuthors, std::string name)
{
    for (Author author : vAuthors) 
    {
        if (author.name == name)        
            return &author;
        
    }
    std::cout << "Автор не найден" << std::endl;
    return nullptr;
}

void Client::printClients(const std::vector <Client>& vClient) 
{
    for (Client client : vClient)
        client.print();
    
}

Client* Client::find(const std::string& name, std::vector <Client>& vClient)
{
    std::cout << "Выбран поиск по имени или фамилии" << std::endl;
    for (Client& client : vClient) 
    {
        if (client.firstName == name)         
            return &client;
        if (client.sureName == name)
            return &client;
        
    }
    std::cout << "Клиент не найден" << std::endl;
    return nullptr;
}

Client* Client::find(size_t cardNum, std::vector<Client>& vClient)
{
    std::cout << "Выбран поиск по номеру читательского билета" << std::endl;
    for (Client& client : vClient) 
    {
        if (client.cardNum == cardNum) 
            return &client;
        
    }
    std::cout << "Клиент не найден" << std::endl;
    return nullptr;
}
