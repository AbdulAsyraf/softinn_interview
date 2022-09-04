#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int length = 10, temp_y, radius;
    char shape = 'g';

    cout << "Please choose a shape\nS - Square\tT - Triangle\tD - Diamond\tC - Circle\n";

    while (!(tolower(shape) == 's' || tolower(shape) == 't' || tolower(shape) == 'd' || tolower(shape) == 'c')){
        cout << ">";
        cin >> shape;
    }

    cout << "Please enter a size\n>";
    cin >> length;

    if (shape == 's'){
    //  square function
        for (int y = length/2; y >= -(length/2); y--){
            for (int x = -(length/2); x <= length/2; x++){
                cout << "* ";
                // cout << x;
            }
            cout << endl;
        }
    }else if (shape == 't'){ 
    //  triangle function
        for (int y = length; y > 0; y--){
            temp_y = length - y;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }else if (shape == 'd'){
    //  diamond function
        length = length/2;

        for (int y = length; y > 0; y--){
            temp_y = length - y;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
        for (int y = 0; y >= -length; y--){
            temp_y = y + length;
            for (int x = -length; x <= length; x++){
                if (x >= (-temp_y) && x <= temp_y){
                    cout << "* ";
                }else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }else if (shape == 'c'){
    //  circle function
        radius = int(length/2);
        for (int y = radius; y >= -radius; y--){
            for (int x = -radius; x <= radius; x++){
                // cout << x;
                if (pow(x, 2) <= (pow(radius, 2) - pow(y, 2))){
                    cout << "* ";
                }else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
}