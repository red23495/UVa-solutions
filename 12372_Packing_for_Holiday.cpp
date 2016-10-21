#include<iostream>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        int a , b, c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if(a <= 20 && b <= 20 && c <= 20)
            cout << "good";
        else cout << "bad";
        cout << endl;
    }
    return 0;
}
