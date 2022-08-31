#include <iostream>

using namespace std;

void display_int(int *input_array, int size_array){

    for (int i = 0; i < size_array; i++){
        if(input_array[i] == 9){
            return;
        }else if (input_array[i]%2){
            cout << "Odd\n";
        }else{
            cout << input_array[i] << endl;
        }
    }

    return;
}

int main(){
    
    int size_array;

    cout << "Enter the size of the array:\t";

    cin >> size_array;

    int *integer_array = new int(size_array);

    cout << "Enter integers for the array\n";

    for (int i = 0; i < size_array; i++){
        cin >> integer_array[i];
    }

    display_int(integer_array, size_array);

    return 0;
}