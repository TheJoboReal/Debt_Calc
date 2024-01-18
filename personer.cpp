#include "personer.h"

Personer::Personer(){};

Person Personer::getPerson(int i){
    return _personer[i];
};

double Personer::getTotalDebt(){
    double totaldebt = 0;

    for(int i = 0; i < _personer.size(); i++){
        totaldebt += _personer[i].getDebt();
        };
    return totaldebt;
};

double Personer::getTotalDebt(std::vector<Person> input){
double totaldebt = 0;

for(int i = 0; i < input.size(); i++){
    totaldebt += input[i].getDebt();
    };
return totaldebt;
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

    each_share = getTotalDebt() / numPersons() - input.getDebt();
    return each_share;
};

void Personer::updateShares(){


    double equal_share = 0.0;
    equal_share= getTotalDebt() / numPersons();

    for(int i=0; i< numPersons(); i++){

        double indv_share = 0.0;

        indv_share = equal_share - _personer[i].getDebt();
        _personer[i].setShare(indv_share);
    }

};

void Personer::whoOwed(){

    std::vector<Person> owed;
    std::vector<Person> owes;

    for(int i=0; i<_personer.size(); i++){
        if(_personer[i].getShare() < 0){
            owed.push_back(_personer[i]);
        }
        else if(_personer[i].getShare() > 0){
            owes.push_back(_personer[i]);
        }
    }

    for(int i=0; i<owed.size(); i++){
        for(int j=0; j<owes.size(); j++){
            std::cout << owes[j].getName() << " skal sende :" << (-owed[i].getShare() / owes.size())/100 << "kr til " << owed[i].getName() << std::endl;
        }
    }
}

void Personer::whatOwed(){
    for(int i=0; i<_personer.size(); i++){
        if(_personer[i].getShare() > 0){
            std::cout << _personer[i].getName() << " skal betale :" << (_personer[i].getShare())/100 << "kr" << std::endl;
        }
        else if(_personer[i].getShare() < 0){
            std::cout << _personer[i].getName() << " skal modtage :" << (-_personer[i].getShare())/100 << "kr" << std::endl;
        }
    }
}

void Personer::printNames(){
    for(int i=0; i<numPersons(); i++){
        std::cout << _personer[i].getName() << std::endl;
    }
}