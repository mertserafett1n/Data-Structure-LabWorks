#include <iostream>
#include<cstdlib>
#include <stdlib.h>
using namespace std;

class NumbersClass{
    int length;
    int *numbers;
    bool isPrime(int);

public:
    NumbersClass(): NumbersClass(10) {}
    NumbersClass(int length): length{length} { numbers = new int[length]; }
    NumbersClass(NumbersClass &);
    ~NumbersClass(){ delete [] numbers; }
    void print();
    void generate();
    void filter(string);
};

NumbersClass::NumbersClass(NumbersClass &source): NumbersClass(source.length){
    //Copying elements
    for(int i = 0; i < length; ++i)
        this->numbers[i] = source.numbers[i];
}


bool NumbersClass::isPrime(int num) {
    for(int i = 2; i < num; i++){
        //Not prime if.
        if( num % i == 0 )
            return false;
    }
    //Prime statement.
    return true;
}

void NumbersClass::print() {
    for(int i = 0; i < length; ++i)
        cout << numbers[i] << " ";
    cout << endl;
}

void NumbersClass::generate() {
    srand(time(NULL));
    for(int i = 0; i < length; ++i)
        numbers[i] = rand() % 10000;
}
void NumbersClass::filter(string typeNum) {
    int i, j, counter = 0;
    // Filtering:
    for(i = 0; i < length; ++i){
        if( isPrime(numbers[i]) && typeNum == "non-prime" ) {
            numbers[i] = -1;
            counter++;
        }
        else if( !(isPrime(numbers[i])) && typeNum == "prime" ) {
            numbers[i] = -1;
            counter++;
        }
    }

    //Now moving elements -1 with bubble sort algorithm.
        for (i = 0; i < length - 1; i++) {
            for (j = 0; j < length - i - 1; j++) {
                if (numbers[j] == -1)
                    swap(numbers[j], numbers[j + 1]);
            }
        }

        //Kind deleting elements -1.
        length = length - counter;
        // I'm not sure that it is true or not.
        numbers = (int*) realloc(numbers,length * sizeof(int));
}

int main(){
    int length;
    cout << "Enter length: ";
    cin >> length;
    NumbersClass objA(length);
    objA.generate();

    NumbersClass objB(objA);
    objB.filter("prime");

    NumbersClass objC(objA);
    objC.filter("non-prime");

    cout << "A: ";
    objA.print();
    cout << "B: ";
    objB.print();
    cout << "C: ";
    objC.print();
    return 0;
}