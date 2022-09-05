#include <iostream>

using namespace std;

int main(){
    
    int size_array;

    cout << "Enter the size of the array:\t";

    cin >> size_array;

    int *integer_array = new int(size_array);

    cout << "Enter integers for the array\n";

    for (int i = 0; i < size_array; i++){
        cin >> integer_array[i];
    }

    cout << "\nDisplaying integers\n";

    for (int i = 0; i < size_array; i++){
        if(integer_array[i] == 9){
            return 0;
        }else if (integer_array[i]%2){
            cout << "Odd\n";
        }else{
            cout << integer_array[i] << endl;
        }
    }

    return 0;
}