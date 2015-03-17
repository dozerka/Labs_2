#include "header.h"
#include "lab2.h"

using namespace std;

Data::Data() : size(10), count(0), firstElem(NULL) { }
Data::Data(int maxsize) : size(maxsize), count(0), firstElem(NULL) { }
Data::Data(const Data& item) : size(item.size), count(0), firstElem(NULL) {
    Elem *temp = item.firstElem;
    while (temp) {
        this->addElem(temp->value);
        temp = temp->next;
    }
}
Data::~Data() {
    Elem *temp = firstElem;
    Elem *temp2 = NULL;
    while (temp){
        temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    count = 0;
}

void Data::addElem(int item) {
    if (count != size) {
        Elem *needElement = new Elem();
        needElement->value = item;
        needElement->next = NULL;
        if (firstElem != NULL) {
            Elem *lastelem = firstElem;
            while (lastelem->next != NULL) {
                lastelem = lastelem->next;
            }
            lastelem->next = needElement;
            count++;
        } else {
            firstElem = needElement;
            count++;
        }
    } else cout << "List is full" << endl;
}

void Data::getElem() {
    if (firstElem == NULL) cout << "List is empty" << endl;
    else {
        cout << "List: ";
        Elem *temp = firstElem;
        while (temp != NULL) {
            cout << temp->value << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void Data::getMax(){
    cout << "MaxSize=" << size << endl;
}

void Stack::push(int item) {
    if (count != size) {
        Elem *needElem = new Elem();
        needElem->value = item;
        needElem->next = firstElem;
        firstElem = needElem;
        count++;
    } else {
        cout << "Stack owerflow" << endl;
    }
}

void Stack::peek() {
    Elem *n = firstElem;
    if (n != NULL){
        cout << "My Stack:";
        while (n != NULL) {
            cout << n->value << "; ";
            n = n->next;
        }
        cout << endl;
    } else cout << "Stack is empty" << endl;
}

void Stack::countOfElem(){
    cout << "Items in stack=" << count << endl;
}

void Stack::pop() {
    if (firstElem != NULL) {
        Elem *temp = firstElem;
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
        Elem *temp = firstElem;
        for (int i = 0; i < item; i++){
            temp = firstElem->next;
            delete firstElem;
            count--;
            firstElem = temp;
        }
    } else cout << "Stack is empty" << endl;
}

void l2() {
    spacer();
    cout << "\nLab #2" << endl;
    spacer();
    
    Stack first;
    first.push(5);
    first.push(10);
    first.push(15);
    first.push(20);
    cout << "First stack:" << endl;
    first.peek();
    Stack c(first);
    cout << "Copyed first stack:" << endl;
    c.peek();
    first.pop();
    cout << "After pop, first stack:" << endl;
    first.peek();
    first.push(5);
    cout << "Peek first stack:" << endl;
    first.peek();
    first.push(55);
    first.push(60);
    cout << "B:" << endl;
    first.peek();
    cout << "stack c(b):" << endl;
    c.peek();
    
    cout << "\nThe end." << endl;
    quit();
}