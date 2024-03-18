#include <iostream>

using namespace std;

class CoffeeMachine{
protected:
    int coffeeAmount;
public:

    CoffeeMachine(): coffeeAmount{0} {}

    void addCoffee(int num) { coffeeAmount += num; }

};

class LatteMachine: public CoffeeMachine{
    int milkAmount;

public:
    LatteMachine(): milkAmount{0} {}

    void addMilk(int num) { milkAmount += num; }

    int makeLatte(int numCup){
        if(numCup <= milkAmount && numCup <= coffeeAmount) {
            milkAmount--;
            coffeeAmount--;
            return 0;
        }
        else if(numCup > coffeeAmount) return -1;
        else return  -2;
    }
};

class FilterCoffeeMachine: public CoffeeMachine{
public:
    int makeFilterCoffee(int numCup){
        if(numCup <= coffeeAmount) {
            coffeeAmount--;
            return 0;
        }
        else return -1;
    }
};

int main() {
    string selection;
    int selectionCoffeeAmount, add;
    LatteMachine objA;
    FilterCoffeeMachine objB;

    //cout << "ObjA.coffeAmount: " << objA.coffeeAmount << endl << "objB.coffeAmount: " << objB.coffeeAmount << endl;

    while (true) {
        cout << "Filter or latte?: ";
        cin >> selection;
        if(selection == "none"){
            cout << "Goodbye!" << endl;
            return 0;
        }
        cout << "How many cups of coffee do you want? ";
        cin >> selectionCoffeeAmount;
        if(selection == "filter"){

            while(objB.makeFilterCoffee(selectionCoffeeAmount) == -1){
                cout << "Not enough coffee! Add: ";
                cin >> add;
                objB.addCoffee(add);
            }

        }
        else if(selection == "latte"){
            while(objA.makeLatte(selectionCoffeeAmount) == -1){
                cout << "Not enough coffee! Add: ";
                cin >> add;
                objA.addCoffee(add);
            }
            while(objA.makeLatte(selectionCoffeeAmount) == -2){
                cout << "Not enough milk! Add: ";
                cin >> add;
                objA.addMilk(add);

            }
        }
        cout << "Enjoy!" << endl;
    }
}