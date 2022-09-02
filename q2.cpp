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
    string input_string, longest_string = "", longest_word = "";
    int length_input_string, longest = 0, longest_word_length = 0;
    char current_char;
    map<char, int> vowels, consonants, numbers, others;

    cout << "Please enter a string:\t";

    // cin >> input_string;
    getline(cin, input_string);
    
    length_input_string = input_string.length();

    for (int i = 0; i < length_input_string; i++){
        if (isalnum(input_string[i])){
            current_char = tolower(input_string[i]);
            if(current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u'){
                if(vowels.insert(pair<char, int>(current_char, 1)).second){
                    ++longest;
                    longest_string += current_char;
                }else{
                    vowels.at(current_char) = vowels.at(current_char) + 1;
                    ++longest;
                    longest_string += current_char;
                }
            }else if (isdigit(current_char)){
                if(numbers.insert(pair<char, int>(current_char, 1)).second){
                    ++longest;
                    longest_string += current_char;
                }else{
                    numbers.at(current_char) = numbers.at(current_char) + 1;
                    ++longest;
                    longest_string += current_char;
                }
            }else{
                if(consonants.insert(pair<char, int>(current_char, 1)).second){
                    ++longest;
                    longest_string += current_char;
                }else{
                    consonants.at(current_char) = consonants.at(current_char) + 1;
                    ++longest;
                    longest_string += current_char;
                }
            }  
        }else{ 
            if(others.insert(pair<char, int>(input_string[i], 1)).second){
                if(longest > longest_word_length){
                    longest_word = longest_string;
                    longest_word_length = longest;
                }
                longest_string = "";
                longest = 0;
            }else{
                others.at(input_string[i]) = others.at(input_string[i]) + 1;
                if(longest > longest_word_length){
                    longest_word = longest_string;
                    longest_word_length = longest;
                }
                longest_string = "";
                longest = 0;
            }
        } 
    }
    
    if(longest > longest_word_length){
        longest_word = longest_string;
        longest_word_length = longest;
    }
    longest_string = "";
    longest = 0;

    if (!vowels.empty()){
        cout << "Vowels:\t\t";
        for (auto& x: vowels){
            cout << "(" << char(toupper(x.first)) << ") " << x.second << "   ";
        }
        cout << endl;
    }

    if(!consonants.empty()){
        cout << "Consonants:\t";
        for (auto& x: consonants){
            cout << "(" << char(toupper(x.first)) << ") " << x.second << "   ";
        }
        cout << endl;
    }

    if(!numbers.empty()){
        cout << "Numbers:\t";
        for (auto& x: numbers){
            cout << "(" << char(toupper(x.first)) << ") " << x.second << "   ";
        }
        cout << endl;
    }

    if(!others.empty()){
        cout << "Symbols:\t";
        for (auto& x: others){
            if(x.first == ' '){
                cout << "(Blank Space) " << x.second << "   ";
            }else{
                cout << "(" << char(toupper(x.first)) << ") " << x.second << "   ";
            }
        }
        cout << endl;
    }

    cout << "\nThe longest word is \"" << longest_word << "\" with a length of " << longest_word_length << " characters"<< endl;
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