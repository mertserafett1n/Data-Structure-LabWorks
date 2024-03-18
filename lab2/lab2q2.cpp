#include <iostream>
#include <string>

using namespace std;

int main(){
    string inpString;
    cout << "Entger any string first:: ";
    getline(cin, inpString);
    string word;
    cout << "Enter substring you want to search:: ";
    cin >> word;
    size_t posWord = inpString.find(word);
    cout << "The Substring [ "  << word << " ]" << " is present in given string at position [ " << posWord + 1 << " ]" << endl; 
    return 0;
}
