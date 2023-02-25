//
// Created by Carlos R. Arias on 5/13/22.
//

#include "phone_book.h"

#include <cstring>
#include <sstream>
#include <iostream>

using std::stringstream;
using std::endl;
using std::ostream;
using std::istream;


PhoneBook::PhoneBook() {
} // https://github.com/csc2430-master/phonebook

PhoneBook::PhoneBook(const PhoneBook &pb) {
    for (int i = 0; i < pb._data.size(); ++i) {
        _data[i] = new Person(*pb._data[i]);
    }
}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < _data.size(); ++i) {
        delete _data[i];
    }
}

const PhoneBook &PhoneBook::operator=(const PhoneBook &rhs) {
    if (this == &rhs)
        return *this;
    for (int i = 0; i < _data.size(); ++i) {
        delete _data[i];
    }
    _data.clear();
    for (int i = 0; i < _data.size(); ++i) {
        _data.push_back(new Person(*rhs._data[i]));
    }
    return *this;
}

bool PhoneBook::AddPerson(const Person &person) {
    _data.push_back(new Person(person));
    return true;
}

bool PhoneBook::RemovePerson(const char *name) {
    // Find the name position
    int foundPosition = -1;
    for (int i = 0; i < _data.size(); ++i) {
        if (strcmp(name, _data[i]->GetName().c_str()) == 0)
            foundPosition = i;
    }
    // if not found, return false
    if (foundPosition == -1)
        return false;
    // if found, delete the person in that position
    delete _data[foundPosition];
    _data.erase(_data.begin() + foundPosition);
    // return true
    return true;
}

Person PhoneBook::FindPerson(const char *name) const {
    for (int i = 0; i < _data.size(); ++i) {
        if (strcmp(name, _data[i]->GetName().c_str()) == 0)
            return *_data[i];
    }
    return Person("","",0);
}

string PhoneBook::ToJSON() const {
    return std::string();
}

string PhoneBook::ToString() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < _data.size(); ++i) {
        if (i != _data.size() - 1)
            ss << _data[i]->ToString() << ", ";
        else
            ss << _data[i]->ToString();
    }
    ss << "]";
    return ss.str();
}

istream &PhoneBook::Read(istream &input) {
    Person dummy("","", 0);
    while (dummy.Read(input))
        if (!AddPerson(dummy))
            break;
    return input;
}

ostream &PhoneBook::Write(ostream &output) const {
    for (int i = 0; i < _data.size(); ++i) {
        _data[i]->Write(output);
        output << endl;
    }
    return output;
}

size_t PhoneBook::Size() const {
    return _data.size();
}

const Person *PhoneBook::GetPerson(size_t index) const {
    if (index >= _data.size())
        return nullptr;
    return _data[index];
}

Person *Phonebook::findInitial(const char *const initial) const{
    for(int i = 0; i < _data.size(); i++){
        if(initial[o] == _data[i]->GetName().c_str()[0]){
            return _data[i];
        }
    }
    return nullptr;
}

