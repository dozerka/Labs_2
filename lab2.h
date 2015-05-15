struct Struct {
    int value;
    Struct *next = NULL;
};

class Data {
private:
    int count;
protected:
    int size;
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
        firstElem = NULL;
        
        int status = item.count;
        int firstNumber = 0;
        
        while (status != 0){

            Struct *temp = new Struct;
            temp->value = item.firstElem->value;
          
            int secondNumber = item.count-firstNumber-1;
            while (secondNumber != 0) {
                temp = temp->next;
                secondNumber--;
            }
            addElem(temp->value);
            firstNumber++;
            status--;
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
    
    Data& operator =(const Data&);
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
        count = item.count;
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