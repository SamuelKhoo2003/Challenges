#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Contact{ 

public: 

    Contact(std::string fn1, std::string ln1, std::string em1, std::string n1) : firstname(fn1), lastname(ln1), email(em1), number(n1){

    }

    std::string print_contacts() const {
        return firstname + " " + lastname + " " + email + " " + number;
    }

    bool check(Contact c, std::string fn, std::string ln) const {
        if(c.firstname  == fn && c.lastname == ln ){
            return true;
        }
        else{
            return false;
        }
    }

private: 

    std::string firstname; 
    std::string lastname; 
    std::string email; 
    std::string number; 

}; 

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
     for(int i = 0; i < contacts.size(); i++){
        if(contacts[i].check(contacts[i], first_name, surname) == true){
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

    std::string ifn, iln, iem, inum; 

    while(infile >> ifn >> iln >> iem >> inum){
        contacts.push_back(Contact(ifn, iln, iem, inum)); 
    }

    infile.close(); 

    for(int i = 0; i < contacts.size(); i++){
        std::cout << contacts[i].print_contacts() << std::endl; 
    }

    std::string firstname, surname; 
    int index; 
    std::cout << "Please enter the first name and surname of the contact you are looking for. " << std::endl; 
    std::cin >> firstname >> surname; 

    index = search_contact(contacts, firstname, surname); 

    if(index == -1){
        std::cout << "Contact not found" << std::endl; 
    }

    else{
        std::cout << contacts[index].print_contacts() << std::endl; 
    }
    
}