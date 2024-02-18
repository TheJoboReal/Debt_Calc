#include "personer.h"
#include <vector>

void ui() {
    Personer personer;
    std::vector<Person> persons;
    char choice;


    while (true) {

        switch (choice){

            std::cout << "Do you want to add another person?    y/n: ";
            std::cin >> choice;

            case 'y':

            std::string name;
            double debt = 0.0;

            std::cout << "Enter name: ";
            std::getline(std::cin, name);  // Use std::getline without additional operations

            std::cout << "Enter debt: ";
            std::cin >> debt;

            persons.emplace_back(name, debt);
            personer.addPerson(persons.back());


            break;
        
        case 'n':

            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "What do you want to do?" << std::endl;
            std::cout << "1. Show persons" << std::endl;
            std::cout << "2. Edit person" << std::endl;
            std::cout << "3. Show results" << std::endl;
            std::cout << "4. Quit" << std::endl;
            std::cin >> choice;

            switch (choice)
            {
            case '1':
                personer.printPersonDebt();
                break;
            
            default:
                break;
            }


            break;
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
}