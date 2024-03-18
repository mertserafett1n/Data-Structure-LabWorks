#include <iostream>
#include<cstdlib>
#include <stdlib.h>
using namespace std;

class Villager{

protected:
    int health;
    int attackPower;

public:
    Villager(): health{20}, attackPower{0} {}
    int attack(Villager &){ return 0; }
    int getHealth() { return health;}
    void setHealth(int health) { this->health = this->health - health;}

};

class Archer: public Villager{
    int nrOfArrows;
public:
    Archer(){
        health = 60;
        attackPower = 40;
        nrOfArrows = 5;
    }

    int attack(Villager &inpObject){
        if(inpObject.getHealth() < 0) return -1;

        return ( rand()%40 );
    }

    int attack(Archer &inpObject){
        if(inpObject.getHealth() < 0) return -1;

        else if(nrOfArrows == 0) return -2;

        nrOfArrows--;
        return ( rand()%40 );
    }

    int getNrOfArrows(){ return nrOfArrows; }

};

int main() {

    srand(time(NULL));
    string stPerson1, stPerson2, empty;
    int numPerson1, numPerson2, counter = 1;
    Villager villagers[5];
    Archer archers[5];
    int tempNum;

    while (true) {
        cout << "Enter command #" << counter++ << ": ";
        cin >> stPerson1 >> numPerson1 >> empty >>stPerson2 >> numPerson2;
        if (stPerson1 == stPerson2 && numPerson1 == numPerson2)
            return 0;
        while (stPerson1 == "Villager") {
            cout << stPerson1 << numPerson1 << " can't attack!" << endl;
            cin.ignore();
            cout << "Enter command #" << counter++ << ": ";
            cin >> stPerson1 >> numPerson1 >> empty >>stPerson2 >> numPerson2;
        }

        if (stPerson2 == "Villager") {
            tempNum = archers[numPerson1-1].attack(villagers[numPerson2-1]);
            if (tempNum != -1) {
                cout << stPerson1 << numPerson1 << " made " << tempNum << " damage to " << stPerson2 << numPerson2
                     << endl;
                villagers[numPerson2-1].setHealth(tempNum);
                tempNum = archers[numPerson1-1].attack(villagers[numPerson2-1]);
            }
            if(villagers[numPerson2-1].getHealth() < 0)
                cout << stPerson2 << numPerson2 << " died!" << endl;
        }
        else if (stPerson2 == "Archer") {
            tempNum = archers[numPerson1-1].attack(archers[numPerson2-1]);

            if (tempNum == -2)
                cout << stPerson1 << numPerson1 << " is out of arrows!" << endl;
            else if(tempNum != -1) {
                cout << stPerson1 << numPerson1 << " made " << tempNum << " damage to " << stPerson2 << numPerson2
                     << endl;
                archers[numPerson2 - 1].setHealth(tempNum);

            }
            if (archers[numPerson2 - 1].getHealth() < 0)
                cout << stPerson2 << numPerson2 << " died!" << endl;


        }

    }
    return 0;
}