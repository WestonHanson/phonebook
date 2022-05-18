#include "person.h"
#include "phone_book.h"

#include <iostream>

using std::cout;
using std::endl;


int main() {
    PhoneBook pb;
    cout << pb.Size() << endl;
    cout << pb.RemovePerson("Josh") << endl;
    cout << pb.AddPerson(Person("James", "2065551234", 9)) << endl;
    cout << pb.AddPerson(Person("Annie", "4255550001", 30)) << endl;
    cout << pb.AddPerson(Person("Mario", "4255550002", -9)) << endl;
    cout << pb.AddPerson(Person("Peter", "4255550003", 5)) << endl;
    cout << pb.AddPerson(Person("Kyra", "4255550014", 1)) << endl;
    cout << pb.AddPerson(Person("Jenny", "4255550131", -4)) << endl;
    cout << pb.FindPerson("Annie").ToString() << endl;
    cout << pb.FindPerson("Jessica").ToString() << endl;
    cout << pb.ToString() << endl;
    cout << pb.RemovePerson("Mario") << endl;
    cout << pb.Size() << endl;
    cout << pb.ToString() << endl;


    return 0;
}
