struct Elem {
    int value;
    Elem *next = NULL;
};

class Data {
private:
    int count;
protected:
    int size;
    Elem *firstElem;
public:
    Data();
    Data(int);
    Data(const Data& x);
    ~Data();
    
    void addElem(int);
    void getElem();
    void getMax();
};

class Stack: public Data {
private:
    int count;
public:
    Stack() {
        count = 0;
    }
    Stack(const Stack &item) {
        size = item.size;
        count = 0;
        firstElem = NULL;
        int h = item.count;
        int i = 0;
        while (h != 0){
            Elem *temp = item.firstElem;
            int c = item.count-i-1;
            while (c != 0){
                temp = temp->next;
                c--;
            }
            addElem(temp->value);
            i++;
            --h;
        }
    };
    ~Stack() {
        Elem *temp = firstElem;
        while (temp){
            temp = firstElem->next;
            delete firstElem;
            count--;
            firstElem = temp;
        }
        delete temp;
    };
    
    void push(int); // добавление в стэк нового элемента
    void peek(); // просмотреть элементы стека
    void countOfElem();
    void pop();     // удаление элемента из стэка
    void pop(int);
};