//
// Created by Carlos R. Arias on 5/11/22.
//

#include "person.h"

#include <sstream>
#include <string>
#include <iostream>
#include <cstring>
#include <cassert>

using std::string;
using std::stringstream;
using std::ostream;
using std::istream;

Person::Person(const char *name, const char *phone, int level) {
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    strcpy(_phone, phone);
    _level = level;
}
Person::Person(const Person& person){
    _name = new char[strlen(person._name) + 1];
    strcpy(_name, person._name);
    strcpy(_phone, person._phone);
    _level = person._level;
}
const Person& Person::operator=(const Person& rhs){
    if (strlen(_name) != strlen(rhs._name)){
        delete[] _name;
        _name = new char[strlen(rhs._name) + 1];
    }
    strcpy(_name, rhs._name);
    strcpy(_phone, rhs._phone);
    _level = rhs._level;

    return *this;
}
string Person::ToString()const{
    stringstream ss;
    ss << _name << " " << _phone << " " << _level;
    return ss.str();
}
string Person::ToJSON() const {
    stringstream ss;
    ss << "{\"name\":\"" << _name << "\", \"phone\":\"" << _phone << "\", \"level\":" << _level << "}";
    return ss.str();
}

string Person::GetName() const {
    return string(_name);

}

string Person::GetPhone() const {
    return string(_phone);
}

int Person::GetLevel() const {
    return _level;
}

bool Person::Equals(const Person &person) const {
    if (strcmp(_phone, person._phone) == 0)
        return true;
    else
        return false;
}

istream &Person::Read(istream &input) {
//    string name, phone;
//    input >> name >> phone;
//    if (name.length() != strlen(_name)){
//        delete[] _name;
//        _name = new char[name.length() + 1];
//    }
//    strcpy(_name, name.c_str());
//    strcpy(_phone, phone.c_str());
//    input >> _level;
    string name, phone;
    int level;
    input >> name >> phone >> level;
    Person temp(name.c_str(),phone.c_str(),level);
    *this = temp;
    return input;
}

ostream &Person::Write(ostream &output) const {
    output << _name << " " << _phone << " " << _level;
    return output;
}

Person::~Person() {
    delete[] _name;
}
