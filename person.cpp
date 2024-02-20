#include "person.h"

std::string Person::getName(){
    return _name;
}

void Person::setShare(double share){
    _each_share = share;
}

double Person::getShare(){
    return _each_share;
}

void Person::setName(std::string name){
    _name = name;
}