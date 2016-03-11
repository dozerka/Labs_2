#include "header.h"

using namespace std;

int main() {
        while (true) {
                cout << "Lab`s available: 1, 2";
                cout << "\nEnter the number of lab or 0 to exit the program: ";
                int x = checkString();

                switch (x) {
                case 0:
                        return 0;
                        break;
                case 1:
                        l1();
                        break;
                case 2:
                        l2();
                        break;
                default:
                        spacer();
                        cout << "\n\nSorry, but this lab is not available. Try again.\n" << endl;
                        break;
                }
        }
        return 0;
}
