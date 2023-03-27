#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstdlib> 
#include <vector> 
#include <fstream> 

struct Contact{
    std::string firstname; 
    std::string surname;
    std::string email;
    std::string number; 
}; 

std::string contacts_to_s(Contact c){
    return c.firstname + " " + c.surname + " " + c.email + " " + c.number; 
}

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
    for(int i = 0; i < contacts.size(); i++){
        if(contacts[i].firstname == first_name && contacts[i].surname == surname){
            return i; 
        }
    }
    return -1; 
}

int main(){

    std::ifstream infile; 
    infile.open("contacts.txt"); 

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 
    }

    std::vector<Contact> contacts; 
    Contact tmp; 

    while(infile >> tmp.firstname >> tmp.surname >> tmp.email >> tmp.number){
        contacts.push_back(tmp); 
    }

    infile.close(); 

    std::string firstname, surname; 
    int index; 
    std::cout << "Please enter the first name and surname of the contact you are looking for. " << std::endl; 
    std::cin >> firstname >> surname; 

    index = search_contact(contacts, firstname, surname); 

    if(index == -1){
        std::cout << "Contact not found" << std::endl; 
    }

    else{
        std::cout << contacts_to_s(contacts[index]) << std::endl; 
    }
    
}