#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void identify(string input_string, int length_input_string){
    vector<char> vowels, consonant, digits, others;
    vector<int> count_vowels, count_consonant, count_digits, count_others;
}

void categorize(){
    string input_string;
    int length_input_string;
    map<char, int> vowels, consonants, others;

    cout << "Please enter a string:\t";

    // cin >> input_string;
    getline(cin, input_string);
    
    length_input_string = input_string.length();

    for (int i = 0; i < length_input_string; i++){
        if (isalpha(input_string[i])){
            cout << input_string[i] << " is an alphanumeric character" << endl;
            if(input_string[i] == 'a')
        }else{
            cout << input_string[i] << " is not an alphanumeric character" << endl; 
        }
        
    }
}

int main(){
    
    // string input_string;
    // int length_input_string;

    // cout << "Please enter a string:\t";

    // cin >> input_string;

    // length_input_string = input_string.length();

    // identify(input_string, length_input_string);
    categorize();

    return 0;
}