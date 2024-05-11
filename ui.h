#include "personer.h"
#include <vector>

void ui() {
    Personer personer;
    char choice;
    bool run_state = true;


    while (run_state) {


            std::cout << std::endl;
            std::cout << "What do you want to do?" << std::endl;
            std::cout << "0. Add people" << std::endl;
            std::cout << "1. Show people" << std::endl;
            std::cout << "2. Edit person" << std::endl;
            std::cout << "3. Show results" << std::endl;
            std::cout << "4. Quit" << std::endl;
            std::cin >> choice;
            std::cout << std::endl;

            switch (choice)
            {
            case '0':
                personer.uiAddPerson();
                std::cout << std::endl;
                break;

            case '1':
                personer.printPersonShare();
                std::cout << std::endl;
                break;
            
            case '2':
                personer.editPerson();
                std::cout << std::endl;
                break;
            
            case '3':
                personer.showResults();
                std::cout << std::endl;
                break;

            case '4':
                std::cout << std::endl;
                run_state = false;
                break;
            }

        }
        }