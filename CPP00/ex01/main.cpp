
#include <iostream>
#include <cctype>
#include <string>
#include "Phonebook.hpp"

int main()
{
    Phonebook   phonebook;
    std::string cmd;
    while (true){
        std::cout << "\nPlease type command: ADD, SEARCH or EXIT" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD"){
            //call add function
            phonebook.addContact();
            std::cout <<"Add function called succesfully" << std::endl;
        }
        else if (cmd == "SEARCH"){
            // call search function
            phonebook.searchContact();
            std::cout <<"Search function called succesfully" << std::endl;
        }
        else if (cmd == "EXIT"){
            std::cout <<"Exit program..." << std::endl;
            break;
        }
        else
            std::cout << "The input command is wrong" << std::endl;
    }
    return 0;
}