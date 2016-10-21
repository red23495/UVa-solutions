#include<iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int  i = 0; i < test; i++){
        int col;
        cin >> col;
        int  x, y;
        cin >> x  >> y;
        int d =  x-y;
        bool v = true;
        for(int i = 0; i < col - 1; i++){
            cin >> x >> y;
            if(v) {
                if(d != x-y)  v = false;
            }
        }
        if(v) cout << "yes";
        else cout << "no";
        cout << endl;
        if(i != test-1) cout << endl;
    }
    return 0;
}
