//
// Created by Carlos R. Arias on 5/13/22.
//

#ifndef PHONEBOOK_PHONE_BOOK_H
#define PHONEBOOK_PHONE_BOOK_H

#include "person.h"

#include <vector>
using std::vector;

class PhoneBook {
private:
    vector<Person*> _data; // needs to be Person* because Person doesn't have default constructor
public:
    PhoneBook();
    PhoneBook(const PhoneBook& pb);
    ~PhoneBook();
    const PhoneBook& operator=(const PhoneBook& rhs);
    bool AddPerson(const Person& person);
    bool RemovePerson(const char* name);
    Person FindPerson(const char* name)const;
    string ToJSON()const;
    string ToString()const;
    istream& Read(istream& input);
    ostream& Write(ostream& output)const;
    size_t Size()const;
    const Person* GetPerson(size_t index)const;
    Person * findInitial(const char *const initial) const;
};


#endif //PHONEBOOK_PHONE_BOOK_H
