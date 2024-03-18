#include <iostream>
using namespace std;

class Calculator{
    float *numbers;
    int length;
public:
    Calculator(): Calculator(1) {} ;
    Calculator(int size): length{size}{ numbers = new float[length]; }
    ~Calculator(){ delete [] numbers; }

    void setNumbers(float *numbers);

    Calculator operator+(const Calculator &obj);
    Calculator operator-(const Calculator &obj);
    Calculator operator*(const Calculator &obj);
    Calculator operator/(const Calculator &obj);
    Calculator &operator=(const Calculator &obj);

    friend ostream& operator<<(ostream &os, const Calculator &obj);
};

std::ostream& operator<<(ostream &os, const Calculator &obj){
    for(int i = 0; i < obj.length; ++i)
        os << obj.numbers[i] << " ";
    return os;
}

Calculator Calculator::operator+(const Calculator &obj) {
    Calculator newObj(obj.length);
    for(int i = 0; i < length; ++i)
        newObj.numbers[i] = this->numbers[i] + obj.numbers[i];

    return newObj;
}

Calculator Calculator::operator-(const Calculator &obj) {
    Calculator newObj(obj.length);
    for(int i = 0; i < length; ++i)
        newObj.numbers[i] = this->numbers[i] - obj.numbers[i];

    return newObj;
}

Calculator Calculator::operator*(const Calculator &obj) {
    Calculator newObj(obj.length);
    for(int i = 0; i < length; ++i)
        newObj.numbers[i] = this->numbers[i] * obj.numbers[i];

    return newObj;
}

Calculator Calculator::operator/(const Calculator &obj) {
    Calculator newObj(obj.length);
    for(int i = 0; i < length; ++i)
        newObj.numbers[i] = this->numbers[i] / obj.numbers[i];

    return newObj;
}

Calculator &Calculator::operator=(const Calculator &obj) {
    delete [] this->numbers;
    this->numbers = new float[obj.length];
    for(int i = 0; i < length; ++i){
        this->numbers[i] = obj.numbers[i];
    }
    return *this;
}

void Calculator::setNumbers(float *numbers) {
    for(int i = 0; i < this->length; ++i){
        this->numbers[i] = numbers[i];
    }
}

int main() {
    int length;
    cout << "Length of the first number set: ";
    cin >> length;
    float *numbers = new float [length];
    Calculator Obj1 (length);
    for(int i = 0; i < length; ++i){
        cin >> numbers[i];
    }
    Obj1.setNumbers(numbers);
    cout << "First set entered: " << Obj1 << endl;

    cout << "Length of the second number set: ";
    cin >> length;
    Calculator Obj2(length);
    delete [] numbers;
    numbers = new float[length];
    for(int i = 0; i < length; ++i){
        cin >> numbers[i];
    }
    Obj2.setNumbers(numbers);
    cout << "First set entered: " << Obj2 << endl;
    char operation;
    Calculator resultObj(length);
    while(true){
        cout << "Choose operation: ";
        cin >> operation;
        switch (operation) {
            case '+':
                resultObj = Obj1 + Obj2;
                break;
            case '-':
                resultObj = Obj1 - Obj2;
                break;
            case '*':
                resultObj = Obj1 * Obj2;
                break;
            case '/':
                resultObj = Obj1 / Obj2;
                break;
            default:
                return 0;
        }
        cout << endl << resultObj << endl;
    }
}