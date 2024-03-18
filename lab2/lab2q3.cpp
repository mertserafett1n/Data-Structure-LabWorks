#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string inpString;
    cout << "Enter a line of string: ";
    getline(cin, inpString);
    int numVowel = 0, numConsonant = 0, numDigit = 0, numWSpace = 0;
    for ( char c: inpString ){
        c = tolower(c);
        if(isalpha(c)){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++numVowel;
            else 
                ++numConsonant;
        }
        else if(isdigit(c))
            ++numDigit;
        else if(isspace(c))
            ++numWSpace;
    }
    cout << "Vowels: " << numVowel << endl << "Consonants: " << numConsonant << endl;
    cout << "Digits: " << numDigit << endl << "White Spaces :" << numWSpace << endl;

    return 0;
}