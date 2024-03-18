#include <iostream>

using namespace std;

int main(){
    cout << "How many numbers letters are you going to enter? ";
    int N;
    cin >> N;
    char *ptrLetter = new char[N];
    int *ptrAmount = new int[N];
    for(int i = 0; i < N; ++i){
        cout << "Enter letter and how many times it will be repeated: ";
        cin >> ptrLetter[i];
        cin >> ptrAmount[i];
    }
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < ptrAmount[i]; ++j){
            cout << ptrLetter[i];
        }
    }
    delete [] ptrLetter;
    delete [] ptrAmount;
    return 0;
}
