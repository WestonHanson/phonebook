//
// Created by Carlos R. Arias on 5/13/22.
//

#include "phone_book.h"

#include <cstring>

PhoneBook::PhoneBook() {
    _size = 0;
    for (int i = 0; i < MAX_FRIENDS; ++i) {
        _data[i] = nullptr;
    }
}

PhoneBook::PhoneBook(const PhoneBook &pb) {
    _size = pb._size;
    for (int i = 0; i < _size; ++i) {
        _data[i] = new Person(*pb._data[i]);
    }
}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < _size; ++i) {
        delete _data[i];
    }
}

const PhoneBook &PhoneBook::operator=(const PhoneBook &rhs) {
    if (this == &rhs)
        return *this;
    for (int i = 0; i < _size; ++i) {
        delete _data[i];
    }
    _size = rhs._size;
    for (int i = 0; i < _size; ++i) {
        _data[i] = new Person(*rhs._data[i]);
    }
    return *this;
}

bool PhoneBook::AddPerson(const Person &person) {
    if (_size == MAX_FRIENDS)
        return false;
    _data[_size] = new Person(person);
    _size++;
    return true;
}

bool PhoneBook::RemovePerson(const char *name) {
    // Find the name position
    // if not found, return false
    // if found, delete the person in that position
    // shift the elements after that position to the "left"
    // set the "last" element to nullptr
    // return true
}

Person PhoneBook::FindPerson(const char *name) const {
    for (int i = 0; i < _size; ++i) {
        if (strcmp(name, _data[i]->GetName().c_str()) == 0)
            return *_data[i];
    }
    return Person("","",0);
}

string PhoneBook::ToJSON() const {
    return std::string();
}

string PhoneBook::ToString() const {
    return std::string();
}

istream &PhoneBook::Read(istream &input) {
    return input;
}

ostream &PhoneBook::Write(ostream &output) const {
    return output;
}
