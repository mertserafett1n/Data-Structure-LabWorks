#include <iostream>
#include <iomanip>
int NumberCar = 5;
using namespace std;

struct car{
    string model;
    int total_km, last_km;
    int does_need;
};

int main(){
    struct car cars[NumberCar];
    int i;
    for(i = 0; i < NumberCar; ++i){
        cout << "Enter car model: ";
        cin >> cars[i].model;
        cout << "Enter total distance: ";
        cin >> cars[i].total_km;
        cout<< "Enter last km: ";
        cin >> cars[i].last_km;
        cars[i].does_need = 0;
        cars[i].does_need = ( (cars[i].total_km - cars[i].last_km) > 10000);
    }
    cout << setw(25) << left <<  "Car" << setw(25) << left << "Total km" << setw(25) << left << "Last km" << setw(25) << left << "Needs Maintainance" << setw(25) << endl; 
    for(i = 0; i < NumberCar; ++i){
        cout << setw(25) << left << cars[i].model << setw(25) << left << cars[i].total_km << setw(25) << left << cars[i].last_km << setw(25);
        if(cars[i].does_need)
            cout << left << "YES" << endl;
        else
            cout << left << "NO" << endl; 
    }
    return 0;
}
