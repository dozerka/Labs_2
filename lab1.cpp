#include "header.h"
#include "lab1.h"
#include <string>

using namespace std;

void Animal::setData() {
        cout<<"Enter type: ";
        cin>>type;
        cout<<"Enter size: ";
        cin>>size;
        cout<<"Enter color: ";
        cin>>color;
        cout<<"Enter count of paws: ";
        pawsCount=checkString();
}

int Animal::mutation() {
    int check;
    cout<<"Do you want mutaion? 1 or 0: ";
    cin>>check;
    if (check == 1) {
        return pawsCount+=rand()%3+1;
    } else return pawsCount;
}

void Animal::getData() {
    cout<<"\nResult:"<<endl;
    cout<<"Type: "<<type<<endl;
    cout<<"Size: "<<size<<endl;
    cout<<"Color: "<<color<<endl;
    if (pawsCount > 4) {
        cout<<"After mutation, the "<<type<<" has "<<pawsCount<<" paws"<<endl;
    } else {
        cout<<type<<" has "<<pawsCount<<" paws"<<endl;
    }
}

void Animal::rename() {
    int check;
    cout<<"Do you want to rename animal? 1 or 0: ";
    cin>>check;
    if (check == 1) {
        cout<<"Enter new name: ";
        cin>>type;
    }
}

bool Animal::checkMutation() {
    if (pawsCount > 4) {
        return true;
    }
    return false;
}

void l1() {
    
    spacer();
    cout << "\nLab #1" << endl;
    spacer();
    
    cout<<"\n\n===== ANIMALS ====="<<endl;
    Animal first, second, *third;
    first.setData();
    first.mutation();
    first.rename();
    first.getData();
    if (first.checkMutation()) {
        cout<<"MUTANT!!1";
    }
    next();
    second.setData();
    second.mutation();
    second.rename();
    second.getData();
    if (second.checkMutation()) {
        cout<<"MUTANT!!1";
    }
    next();
    third = new Animal;
    third->setData();
    third->mutation();
    third->rename();
    third->getData();
    if (third->checkMutation()) {
        cout<<"MUTANT!!1";
    }

    cout << "\n\nThe end." << endl;
    quit();
}