#include "personer.h"

char person_choice = true;
bool person_adder = true;


Personer::Personer(){};

Person Personer::getPerson(int i){
    return _personer[i];
};

double Personer::getTotalShare(){
    double totalshare = 0;

    for(int i = 0; i < _personer.size(); i++){
        totalshare += _personer[i].getShare();
        };
    return totalshare;
};

double Personer::getTotalShare(std::vector<Person> input){
double totalshare = 0;

for(int i = 0; i < input.size(); i++){
    totalshare += input[i].getShare();
    };
return totalshare;
};

size_t Personer::numPersons(){
    return _personer.size();
}

void Personer::addPersoner(std::vector<Person> input){
    _personer = input;
};

void Personer::addPerson(Person input){
    _personer.push_back(input);
};

double Personer::getEqualShare(Person input){
    double each_share = 0.0;

    each_share = getTotalShare() / numPersons() - input.getShare();
    return each_share;
};

void Personer::updateShares(){

    double equal_share = 0.0;
    equal_share= getTotalShare() / numPersons();

    for(int i=0; i< numPersons(); i++){

        double indv_share = 0.0;

        indv_share = equal_share - _personer[i].getShare();
        _personer[i].setShare(indv_share);
    }

};

// void Personer::whoOwed(){

//     std::vector<Person> owed;
//     std::vector<Person> owes;

//     for(int i=0; i<_personer.size(); i++){
//         if(_personer[i].getShare() < 0){
//             owed.push_back(_personer[i]);
//         }
//         else if(_personer[i].getShare() > 0){
//             owes.push_back(_personer[i]);
//         }
//     }

//     for(int i=0; i<owed.size(); i++){
//         for(int j=0; j<owes.size(); j++){
//             std::cout << owes[j].getName() << " skal sende :" << -owed[i].getShare() / owes.size() << "kr til " << owed[i].getName() << std::endl;
//         }
//     }
// }

void Personer::whoOwed() {
    std::vector<Person> owed;
    std::vector<Person> owes;

    // Separate people who owe money and people who are owed money
    for (int i = 0; i < _personer.size(); i++) {
        if (_personer[i].getShare() < 0) {
            owed.push_back(_personer[i]);
        } else if (_personer[i].getShare() > 0) {
            owes.push_back(_personer[i]);
        }
    }

    // Iterate through people who are owed money
    for (int i = 0; i < owed.size(); i++) {
        double totalOwed = -owed[i].getShare();

        // Iterate through people who owe money
        for (int j = 0; j < owes.size(); j++) {
            if (totalOwed > 0) {
                double share = std::min(totalOwed, owes[j].getShare());

                if(share!=0){
                    std::cout << owes[j].getName() << " skal sende: " << share << "kr til " << owed[i].getName() << std::endl;
                }
                // Update the share for the person who owes money
                owes[j].setShare(owes[j].getShare() - share);

                // Update the share for the person who is owed money
                owed[i].setShare(owed[i].getShare() + share);

                totalOwed -= share;
            }
        }
    }
}

void Personer::whatOwed(){
    for(int i=0; i<_personer.size(); i++){
        if(_personer[i].getShare() < 0){
            std::cout << _personer[i].getName() << " skal modtage :" << -_personer[i].getShare() << "kr" << std::endl;
        }
    }
}

void Personer::printNames(){

    for(int i=0; i<numPersons(); i++){
        std::cout << _personer[i].getName() << std::endl;
    }
}

void Personer::showResults(){


            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;

            updateShares();
            whoOwed();

            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
            whatOwed();


            // Clear the input buffer
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;
    
}

void Personer::printPersonShare(){

    std::cout << "--------------------------------------------------------------------" << std::endl;

    for(int i=0; i<numPersons(); i++){
        std::cout << i << " " << _personer[i].getName() << " :" << _personer[i].getShare() << std::endl;
    }

    std::cout << "--------------------------------------------------------------------" << std::endl;
} 

void Personer::setPersoner(std::vector<Person> input){
    _personer = input;
};

void Personer::removePerson(int input){
      _personer.erase (_personer.begin()+input);
}

void Personer::editPerson(){
            int person;

            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << "--------------------------------------------------------------------" << std::endl;
            std::cout << std::endl;

            printPersonShare();

            std::cout << std::endl;

            std::cout << "Who do you want to edit? :";
            std::cin >> person;
            std::cout << std::endl;


            int removeOrEdit;
            std::cout << "1:Remove or 2:edit person? :";
            std::cin >> removeOrEdit;
            std::cout << std::endl;

            switch(removeOrEdit){

                case 1:
                    removePerson(person);
                    break;

                case 2:
                double newShare;
                    std::cout << "New share: ";
                    std::cin >> newShare;
                    std::cout << std::endl;

                    _personer[person].setShare(newShare);
                    std::cout << std::endl;
                    std::cout << std::endl;

                    std::cout << "--------------------------------------------------------------------" << std::endl;
                    std::cout << getPerson(person).getName() << "'s new share is " << newShare << std::endl;
                    std::cout << "--------------------------------------------------------------------" << std::endl;

                    // Person personShare;
                    // personShare.setName(_personer[person].getName());
                    // personShare.setShare(newShare);

                    // removePerson(person);
                    // addPerson(personShare);

                    break;
            }



}

void Personer::uiAddPerson(){

    while(person_adder){

        std::cout << "Do you want to add another person?    y/n: ";
        std::cin >> person_choice;
        std::cout << std::endl;

        switch (person_choice){
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

                addPerson(person);

                std::cout << std::endl;
                printPersonShare();
                std::cout << std::endl;
                break;
            }

            case 'n':
            // Clear the input buffer
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << std::endl;
            printPersonShare();
            std::cout << std::endl;

            person_adder = false;
            break;
        }
    }

}