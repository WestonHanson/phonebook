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
string Person::ToString()const{
    return string(_name);
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
    assert(false);
    return input;
}

ostream &Person::Write(ostream &output) const {
    assert(false);
    return output;
}

Person::~Person() {
    delete[] _name;
}
