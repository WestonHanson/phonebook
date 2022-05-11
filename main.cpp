#include "person.h"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "Starting..." << endl;
    char n[]  = "Abdul";
    char p[] = "4255550909";
    Person abdul(n, p, 10);
    cout << abdul.ToString() << endl;

    return 0;
}
