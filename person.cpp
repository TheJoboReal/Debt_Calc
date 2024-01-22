#include "person.h"

int Person::getDebt(){
    return _debt;
}

std::string Person::getName(){
    return _name;
}

void Person::setShare(double share){
    _each_share = share;
}

double Person::getShare(){
    return _each_share;
}
