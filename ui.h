#include "personer.h"
#include <vector>

void ui() {
    Personer personer;
    std::vector<Person> persons;

    while (true) {
        std::string name;
        double debt = 0.0;

        std::cout << "Enter name: ";
        std::getline(std::cin, name);  // Use std::getline without additional operations

        std::cout << "Enter debt: ";
        std::cin >> debt;

        persons.emplace_back(name, debt);
        personer.addPerson(persons.back());

        char choice;
        std::cout << "Do you want to add another person?    y/n: ";
        std::cin >> choice;

        if (choice == 'n') {

            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;

            personer.updateShares();
            personer.whoOwed();

            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
            personer.whatOwed();


            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;

            break;
        }

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}