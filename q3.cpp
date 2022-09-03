#include <iostream>

using namespace std;

int main(){
    int length, temp_y;
    char shape;
    length = 9;

    shape = 'd';

    if (shape == 's'){
    //  square function
        for (int y = length/2; y >= -(length/2); y--){
            for (int x = -(length/2); x <= length/2; x++){
                //cout << "*";
                cout << x;
            }
            cout << endl;
        }
    }else if (shape == 't'){ 
    //  triangle function
        for (int y = length; y > 0; y--){
            temp_y = length - y;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }else if (shape == 'd'){
    //  diamond function
        length = length/2;
        // if (length%2){
        //     length = length/2;
        // }else{
        //     length = length/2 + 1;
        // }

        for (int y = length; y > 0; y--){
            temp_y = length - y;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        for (int y = 0; y >= -length; y--){
            temp_y = y + length;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}