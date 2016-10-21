#include<iostream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int n;
        cin >> n;
        n = (((((n*567)/9)+7492)*235)/47)-498;
        int r = (n%100)/10;
        cout << ((r<0)?-r:r) << endl;
    }
    return 0;
}
