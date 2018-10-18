#include <iostream>
using namespace std;

int arrayToCoorX(int arrayID){
    int x;
    if (arrayID % 6 == 0){
        x = arrayID / 6;
    }
    else{
        x = arrayID / 6;
        x++;
    }
    return x;
}
int arrayToCoorY(int arrayID){
    int y = arrayID % 6;
    if (y == 0){
        y = 6;
    }
    return y;
}

int main()
{
    for (int i = 1; i <= 36; i++)
    cout << i << " | " << arrayToCoorX(i) << "|" << arrayToCoorY(i) << endl;
    
    return 0;
}
