#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int r1,c1,r2,c2;
    while(cin >> r1 >> c1 >> r2 >> c2 && r1){
        if(r1 == r2 && c1 == c2) cout << 0;
        else if(r1 == r2 || c1 == c2 || abs(r1-r2) == abs(c1-c2)){
            cout << 1;
        }
        else cout << 2;
        cout << endl;
    }
    return 0;
}
