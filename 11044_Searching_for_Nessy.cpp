#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        double row, column;
        cin >> row >> column;
        row = ceil((row-2)/3);
        column = ceil((column-2)/3);
        cout << int(row*column) << endl;
    }
    return 0;
}
