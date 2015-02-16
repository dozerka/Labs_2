#include "header.h"

using namespace std;

int quit(){
    string number;
    cout<<"Exit or continue? Enter 'exit'/'continue' ('e'/'c'): ";
    while (true){
        cin>>number;
        if (number=="e"||number=="exit") exit(EXIT_SUCCESS);
        if (number=="c"||number=="continue") return 0;
        cout<<"Incorrect! Try again: ";
    }
    return 0;
}
