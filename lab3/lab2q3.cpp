#include <iostream>
#include <string>

using namespace std;

struct NUMBERLIST{
    int array [10];
    string direction;
};

void funcPTR( NUMBERLIST *ptr ){
    if(ptr->direction == "left-to-right"){
        for(int i = 0; i < 9; ++i){
            ptr->array[i+1] += ptr->array[i];
            }
    }
    else{
        for(int i = 9; i > 0; --i){
            ptr->array[i-1] += ptr->array[i];
        }
    }
}

void funcREF( NUMBERLIST*&ref ){
    if(ref->direction == "left-to-right"){
        for(int i = 0; i < 10; ++i){
            ref->array[i+1] += ref->array[i];
        }
    }
    else{
        for(int i = 9; i > 0; --i){
            ref->array[i-1] += ref->array[i];
        }
    }
}
void printArray(int *arr, int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int main(){
    struct NUMBERLIST numberL;
    NUMBERLIST *ptr_to_numberL = &numberL;
    cout << "Enter 10 integers and order of summation: ";
    for(int i = 0 ; i < 10; ++i){
        cin >> ptr_to_numberL->array[i];
    }
    cin >> ptr_to_numberL->direction;
    
    funcPTR(ptr_to_numberL);

    // funcREF(ptr_to_numberL);

    cout << "Result: ";
    printArray(ptr_to_numberL->array, 10);
    delete ptr_to_numberL;
    return 0;
}