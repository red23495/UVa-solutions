#include<iostream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int n;
        cin >> n;
        int min = 100;
        int max = -1;
        for(int i = 0; i < n; i++){
            int in;
            cin >> in;
            if(in < min) min = in;
            if(in > max) max = in;
        }
        cout << 2*(max-min) << endl;
    }
    return 0;
}
