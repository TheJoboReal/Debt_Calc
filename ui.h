#include "personer.h"
#include <vector>

void ui() {
    Personer personer;
    char choice;
    bool run_state = true;
    bool person_adder = true;


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
                
                while(person_adder){

                    std::cout << "Do you want to add another person?    y/n: ";
                    std::cin >> choice;
                    std::cout << std::endl;

                    switch (choice){
                        case 'y':{

                            Person person;

                            std::string name;
                            double share = 0.0;

                            std::cout << "Enter name: ";
                            std::cin >> name;

                            std::cout << std::endl;

                            std::cout << "Enter share: ";
                            std::cin >> share;

                            person.setName(name);
                            person.setShare(share);

                            personer.addPerson(person);

                            std::cout << std::endl;
                            break;
                        }

                        case 'n':
                        // Clear the input buffer
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                        person_adder = false;
                        break;
                    }
                }

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