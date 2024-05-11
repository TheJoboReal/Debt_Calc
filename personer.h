#ifndef PERSONER_H
#define PERSONER_H

#include <iostream>
#include <cmath>
#include <vector>

#include "person.h"


class Personer : public Person{
private:
    std::vector<Person> _personer;
    int _antalpersoner = _personer.size();

public:
    Personer(std::vector<Person> personer):Person("DefaultName", 0.0), _personer(personer), _antalpersoner(_personer.size()){};
    Personer();


    Person getPerson(int i);
    double getTotalShare();
    double getTotalShare(std::vector<Person> input);
    double getEqualShare(Person input);

    void setPersoner(std::vector<Person> input);
    void setShare(double share);
    void addPersoner(std::vector<Person> input);
    void addPerson(Person input);
    void updateShares();
    void whoOwed();
    void whatOwed();
    void printNames();
    void showResults();
    void printPersonShare();
    void editPerson();
    void removePerson(int input);
    void uiAddPerson();

    size_t numPersons();

    std::vector<Person> getPersoner();

};







#endif  //PERSOENR_H