#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int x,b;
        cin >> x >> b;
        for(int j = 0; j < x; j++){
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int diff1 = abs(r1 - r2), diff2=abs(c1-c2);
            if((r1 == r2) && (c1 == c2)) cout << 0;
            else if(diff1 == diff2) cout << 1;
            else if((diff1%2 == diff2%2)) cout << 2;
            else cout << "no move";
            cout << endl;
        }
    }
}
