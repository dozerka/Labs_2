#include "header.h"
#include "lab2.h"

using namespace std;

void Data::addElem(int item) {
    if (count != size) {
        Struct *elem = new Struct();
        elem->value = item;
        elem->next = NULL;
        if (firstElem != NULL) {
            Struct *lastElem = firstElem;
            while (lastElem->next != NULL) {
                lastElem = lastElem->next;
            }
            lastElem->next = elem;
            count++;
        } else {
            firstElem = elem;
            count++;
        }
    } else cout << "List is full" << endl;
}

void Data::getElem() {
    if (firstElem == NULL) cout << "List is empty" << endl;
    else {
        cout << "List: ";
        Struct *temp = firstElem;
        while (temp != NULL) {
            cout << temp->value << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void Data::getMax(){
    cout << "Max size: " << size << endl;
}

void Stack::push(int item) {
    if (count != size) {
        Struct *elem = new Struct();
        elem->value = item;
        elem->next = firstElem;
        firstElem = elem;
        count++;
    } else {
        cout << "Stack owerflow" << endl;
    }
}

void Stack::push() {
        Struct *elem = new Struct();
        int item;
        cout << "Enter element of stack: ";
        item = checkString();
        elem->value = item;
        elem->next = firstElem;
        firstElem = elem;
        count++;
}

void Stack::peek() {
    Struct *item = firstElem;
        while (item != NULL) {
            cout << item->value << " ";
            item = item->next;
        }
}

void Stack::countOfElem(){
    cout << "Items in stack =" << count << endl;
}

void Stack::pop() {
    if (firstElem != NULL) {
        Struct *temp = firstElem;
        temp = firstElem->next;
        delete firstElem;
        count--;
        firstElem = temp;
    } else {
        cout << "Stack is empty" << endl;
    }
}

void Stack::pop(int item){
    if (firstElem != NULL){
        Struct *temp = firstElem;
        for (int i = 0; i < item; i++){
            temp = firstElem->next;
            delete firstElem;
            count--;
            firstElem = temp;
        }
    } else cout << "Stack is empty" << endl;
}

int Stack::enterElement(int item) {
    cout << "Enter element of stack:";
    
    return item;
}

void l2() {
    spacer();
    cout << "\nLab #2" << endl;
    spacer();
    
    Stack first;
    first.setName();
    
    int stackSize, countElements = 0;
    cout << "Enter size of stack: ";
    stackSize = checkString();
    for (int i = 0; i < stackSize; i++) {
        first.push();
    }
    
    cout << "\n" << first.getName() << " stack: " << endl;
    first.peek();
    Stack second(first);
    second.setName();
    cout << "\nCopy " << first.getName() << " stack to " << second.getName() << " stack" << endl;
    second.peek();
    cout << "\nPoping 1 element in " << first.getName() << " stack";
    first.pop();
    cout << "\nAfter pop, " << first.getName() << " stack: " << endl;
    first.peek();
    
    int status;
    cout << "\nDo you want add elements to " << first.getName() << " stack? 1 or 0: ";
    cin >> status;
    if (status) {
        cout << "How much elements you want add: ";
        countElements = checkString();
        for (int i = 0; i < countElements; i++) {
            first.push();
        }
    }
    cout << "\nPeek " << first.getName() << " stack: " << endl;
    first.peek();
    
    cout << "\n" << second.getName() << " stack" << endl;
    second.peek();
    
    cout << "\nThe end." << endl;
    quit();
}