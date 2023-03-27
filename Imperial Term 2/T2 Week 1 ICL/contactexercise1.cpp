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

    for(int i = 0; i < contacts.size(); i++){
        std::cout << contacts_to_s(contacts[i]) << std::endl; 
    }
}