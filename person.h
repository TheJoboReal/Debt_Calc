#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
private:
    std::string _name;
    double _debt;
    double _each_share;

public:
    Person(std::string name, double debt): _name(name){
        _debt = debt;
    };
    Person() {};

    int getDebt();
    std::string getName();

    void setShare(double share);
    double getShare();
};

#endif  //PERSON_H