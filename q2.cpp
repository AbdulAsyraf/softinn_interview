#include <iostream>
#include <vector>
#include <string>

using namespace std;

void identify(string input_string, int length_input_string){
    vector<char> vowels, consonant, digits, others;
    vector<int> count_vowels, count_consonant, count_digits, count_others;
}

int main(){
    
    string input_string;
    int length_input_string;

    cout << "Please enter a string:\t";

    cin >> input_string;

    length_input_string = input_string.length();

    identify(input_string, length_input_string);

    return 0;
}