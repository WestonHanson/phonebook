#include "person.h"

#include <iostream>

using std::cout;
using std::endl;

void WhatABeautifulName(Person p);

int main() {
    Person x[6];
    cout << "Starting..." << endl;
    char n[]  = "Abdul";
    char p[] = "4255550909";
    Person abdul(n, p, 10);
    cout << abdul.ToString() << endl;

    Person jeff("Jeff", "0000000000", -1);
    jeff = abdul;

    WhatABeautifulName(abdul);

    Person* maria = nullptr;

    maria = new Person("Maria", "4255550001", 100);
    cout << maria->ToJSON() << endl;
    delete maria;
    return 0;
}
void WhatABeautifulName(Person p){
    cout << p.ToString() << " is beautiful... on the inside" << endl;
}
