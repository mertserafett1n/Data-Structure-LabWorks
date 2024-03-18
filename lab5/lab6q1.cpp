#include <iostream>

using namespace std;

class upDownNumbers {
    int start;
    int length;
    int *numbers;
public:
    upDownNumbers(int, int);
    upDownNumbers(upDownNumbers &);
    ~upDownNumbers();
    void generate();
    void print();


    int getStart() ;

    int getLength();

    void setStart(int start);

};

upDownNumbers::upDownNumbers(int length, int start): length{length}, start{start} {
    numbers = new int[length];
    generate();
}

upDownNumbers::upDownNumbers(upDownNumbers &source): upDownNumbers(source.length, source.start)  {}

void upDownNumbers::generate() {
    numbers[0] = start;
    for(int i = 1; i < length; ++i){
        if(numbers[i-1] % 2)
            numbers[i] = 3 * numbers[i-1] - 1;
        else
            numbers[i] = (numbers[i-1] / 2) + 5;
    }
}

void upDownNumbers::print() {
    for(int i = 0; i < length; ++i)
        cout << numbers[i] << " ";
    cout << endl;
}

upDownNumbers::~upDownNumbers() {
    delete [] numbers;
}

int upDownNumbers::getStart() {
    return start;
}

int upDownNumbers::getLength()  {
    return length;
}

void upDownNumbers::setStart(int start) {
    upDownNumbers::start = start;
}

int main() {
    int start, length;
    cout << "Enter length and start for Object A: ";
    cin >> length >> start;
    upDownNumbers objA(length, start);

    cout << "Object A (start: "<<objA.getStart() << ", length: "<< objA.getLength() << "): ";
    objA.print();

    upDownNumbers objB(objA);
    cout << "Object B (start: "<<objB.getStart() << ", length: "<< objB.getLength() << "): ";
    objB.print();

    cout << "Enter new start for Object B: ";
    cin >> start;
    objB.setStart(start);
    objB.generate();

    cout << "b.start is " << objB.getStart() << " now" << endl;
    cout << "Object A (start: "<<objA.getStart() << ", length: "<< objA.getLength() << "): ";
    objA.print();
    cout << "Object B (start: "<<objB.getStart() << ", length: "<< objB.getLength() << "): ";
    objB.print();

    return 0;
}