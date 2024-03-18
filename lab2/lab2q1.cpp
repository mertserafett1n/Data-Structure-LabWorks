#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    ofstream writeFile(fileName);
    string infoToFile ;
    cout << "Enter information to store.." << endl;
    cin.ignore();
    getline(cin, infoToFile);
    writeFile << infoToFile << endl;
    char want_enter_more;
    cout << "Want to enter more ? <y/n>.. ";
    cin >> want_enter_more;
    while(want_enter_more == 'y'){
        cin.ignore();
        getline(cin, infoToFile);
        writeFile << infoToFile << endl;
        cout << "Want to enter more ? <y/n>.. ";
        cin >> want_enter_more;
    }
    writeFile.close();
    cout << "The information succesfully stored in the file..." << endl;
    cout << "Want to see ? <y/n>.. ";
    char wantSee;
    cin >> wantSee;
    if(wantSee == 'y'){
        ifstream readFile(fileName);
        cout << "The file contains: " << endl;
        string infoFromFile;
        while(getline (readFile, infoFromFile) ){
            cout << infoFromFile << endl;
        }
        readFile.close();
    }
return 0;
}