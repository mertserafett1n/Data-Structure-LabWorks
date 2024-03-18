#include <iostream>

using namespace std;

class Calculator{
public:
    int op1, op2;
    string operat;
    double result;
    void run();
};

void Calculator::run(){
    if(operat == "substract")
        result = op2 - op1;
    else if(operat == "divide")
        result = op1 / op2;
    else if(operat == "multiply")
        result = op1 * op2;
    else if(operat == "add")
        result = op1 + op2;
  printf("Result is: %lf", result);
}

int main() {
    Calculator calc1;
    string ignore;

    cout << "Enter your operation: ";
    cin >> calc1.operat >> calc1.op1 >> ignore >> calc1.op2;

    calc1.run();
    return 0;
}