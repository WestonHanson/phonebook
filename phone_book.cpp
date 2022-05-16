//
// Created by Carlos R. Arias on 5/13/22.
//

#include "phone_book.h"

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
}

const PhoneBook &PhoneBook::operator=(const PhoneBook &rhs) {
    return *this;
}

bool PhoneBook::AddPerson(const Person &person) {
    return false;
}

bool PhoneBook::RemovePerson(const char *name) {
    return false;
}

Person PhoneBook::FindPerson(const char *name) const {
    return Person(nullptr, nullptr);
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
