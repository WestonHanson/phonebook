#include "person.h"
#include "phone_book.h"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;
using std::ofstream;
using std::ifstream;

int Menu();

int main() {
    cout << "How big do you want your phonebook to be: ";
    size_t number;
    cin >> number;
    PhoneBook pb(number);

    int option;
    while ((option = Menu()) != 7){
        if (option == 1){
            if (pb.Size() == pb.Capacity()){
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
            for (int i = 0; i < pb.Size(); ++i) {
                cout << i  << "\t" << pb.GetPerson(i)->ToString() << endl;
            }
        }else if (option == 4){
            cout << "List Good Friends" << endl;
            // Assume >=5 is good friend
            for (int i = 0; i < pb.Size(); ++i) {
                if (pb.GetPerson(i)->GetLevel() > 5)
                    cout << pb.GetPerson(i) ->ToString() << endl;
             }
        }else if (option == 5){
            string filename;
            cout << "Yo DJ, spin that file: ";
            cin >> filename;
            ifstream file(filename);
            if (file.fail()){
                cerr << "You have failed me for the last time" << endl;
                continue;
            }
            pb.Read(file);
        }else if (option == 6){
            string filename;
            cout << "Yo, give me your filename: ";
            cin >> filename;
            ofstream file(filename);
            if (file.fail()){
                cerr << "Could not open file " << filename << endl;
                continue;
            }
            pb.Write(file);
            file.close();
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


