//
// Created by Carlos R. Arias on 5/13/22.
//

#ifndef PHONEBOOK_PHONE_BOOK_H
#define PHONEBOOK_PHONE_BOOK_H

#include "person.h"

const int MAX_FRIENDS = 5;

class PhoneBook {
private:
    Person* _data[MAX_FRIENDS];
    size_t _size;
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

};


#endif //PHONEBOOK_PHONE_BOOK_H
