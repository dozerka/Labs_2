struct Struct {
    int value;
    Struct *next = NULL;
};

class Data {
private:
    int count;
protected:
    int size, n;
    Struct *firstElem;
public:
    Data() {
        size = 100;
        count = 0;
        firstElem = NULL;
    };
    Data(int maxsize) {
        size = maxsize;
        count = 0;
        firstElem = NULL;
    };
    Data(const Data& item) {
        size = item.size;
        count = 0;
        firstElem = NULL;
        
        int h = item.count;
        int i = 0;
        while (h != 0){
            Struct *temp = item.firstElem;
            int c = item.count-i-1;
            while (c != 0){
                temp = temp->next;
                c--;
            }
            addElem(temp->value);
            i++;
            --h;
        }
        
        Struct *temp = item.firstElem;
        while (temp) {
            this->addElem(temp->value);
            temp = temp->next;
        }
    };
    ~Data() {
        Struct *tempFirst = firstElem;
        Struct *tempSecond = NULL;
        while (tempFirst){
            tempSecond = tempFirst->next;
            delete tempFirst;
            tempFirst = tempSecond;
        }
        count = 0;
    };
    
    void addElem(int);
    void getElem();
    void getMax();
};

class Stack: public Data {
private:
    int count;
    std::string name;
public:
    Stack() {
        count = 0;
    }
    Stack(const Stack &item) : Data(item) {
        size = item.size;
    }

    ~Stack() {
        Struct *temp = firstElem;
        while (temp){
            temp = firstElem->next;
            delete firstElem;
            count--;
            firstElem = temp;
        }
        delete temp;
    }
    
    void setName() {
        std::cout << "\nEnter the name of stack: ";
        std::cin >> name;
    }
    
    std::string getName() { return name; }

    void push();
    void push(int);     // добавление в стэк нового элемента
    void peek();        // просмотреть элементы стека
    void countOfElem(); //
    void pop();         // удаление элемента из стэка
    void pop(int);
    
    int enterElement(int);
};