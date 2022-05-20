#include "person.h"
#include "phone_book.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

int Menu();

int main() {
    PhoneBook pb;
    int option;
    while ((option = Menu()) != 7){
        if (option == 1){
            if (pb.Size() == MAX_FRIENDS){
                cout << "Phonebook full, cannot add more" << endl;
                continue;
            }
            // Add a Person
            string name, phone;
            int level;
            cout << "Input Person Data:" << endl;
            cout << "\tName: ";
            cin >> name;
            cout << "\tPhone: ";
            cin >> phone;
            if (phone.length() > 10){
                cerr << "Dummy I only have friends in the US! Please use that format" << endl;
                continue;
            }
            cout << "\tLevel: ";
            cin >> level;
            if (cin.fail()){
                cin.clear();
                cin.ignore(255, '\n');
                cerr << "You are supposed to enter a number!" << endl;
                continue;
            }
            bool ok = pb.AddPerson(Person(name.c_str(), phone.c_str(), level));
            if (!ok){
                cout << "Your Phonebook is Full, buy a new one, or dump some friends, not that you have that many" << endl;
            }else{
                cout << "Friend " << name << " added to the Phonebook" << endl;
            }

        }else if (option == 2){
            cout << "Remove a Person" << endl;
        }else if (option == 3){
            // List all my friends on the Phonebook
            cout << "My Phonebook has " << pb.Size() << " people" << endl;
            cout << pb.ToString() << endl;
        }else if (option == 4){
            cout << "List Good Friends" << endl;
        }else if (option == 5){
            cout << "Read from File" << endl;
        }else if (option == 6){
            cout << "Write to File" << endl;
        }else{
            cerr << "Not an option!" << endl;
        }
    }


    return 0;
}

int Menu(){
    int option;
    bool invalid = true;
    while (invalid){
        cout << "1. Add Person" << endl;
        cout << "2. Remove Person" << endl;
        cout << "3. List All" << endl;
        cout << "4. List Good Friends" << endl;
        cout << "5. Read a File" << endl;
        cout << "6. Write a File" << endl;
        cout << "7. Exit" << endl;
        cin >> option;
        if (cin.fail()){
            cin.clear();
            cin.ignore(255, '\n');
            cerr << "You are supposed to enter a number!" << endl;
        }else{
            if (option < 1 || option > 7){
                cerr << "That option is not in the menu" << endl;
            }else{
                invalid = false;
            }
        }
    }
    return option;
}


