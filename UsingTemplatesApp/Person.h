#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

class Person
{
private:
    //Data members
    string name;
    string email;
public:
    //Mutators-Accessors
    void setName(string nameVal) {
        name = nameVal;
    }

    void setEmail(string emailValue) {
        //Validating email format
        int pos1 = emailValue.find("@");
        int pos2 = emailValue.find(".", pos1 + 1);
        int pos3 = emailValue.find("@", pos1 + 1);
        if (!( pos1 > 0 && pos2 > pos1 && pos3 == -1))
        {
            throw (exception)("invalid email");
        }
        //email is valid!
        email = emailValue;
    }


    string getName() const { return name; }
    string getEmail() const { return email; }
    
    //Constructor
    Person(string nameVal = "na", string emailVal = "na") {
        setName(nameVal);
        setEmail(emailVal);
    }

    //User-defined methods
    string toString() const {
        stringstream sout;
        sout << this << " Person [Name: " << getName() << ", Email: " << getEmail() << "]";
        return sout.str();
    }

    friend ostream& operator<< (const ostream& sout, const Person& p);

    bool operator< (const Person& otherPerson) {
        return (this->getName().size() < otherPerson.getName().size());
    }

    
};

ostream& operator<< (ostream& sout, const Person& p) {
    sout <<  " Person [Name: " << p.getName() << ", Email: " << p.getEmail() << "]";
    return sout;
}
