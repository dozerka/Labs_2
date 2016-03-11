#include "header.h"

using namespace std;

int checkString() {
        int number;
        string clearString;
        while (!(cin >> number)) {
                cin.clear();
                cin >> clearString;
                cout << "Incorrect number! Try again: ";
        }
        return number;
}
