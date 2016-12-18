#include<iostream>

using namespace std;

int main(){
    int x;
    while(cin >> x && x){
        int n1 = 0, n2 = 0;
        bool turn = true;
        int i = 31;
        int p = (1 << 30);
        while(i--){
            n1>>=1;
            n2>>=1;
            int t = (x & 1);
            if(t){
                if(turn) n1 |= p;
                else n2 |= p;
                turn = !turn;
            }
            x >>=1;
        }
        cout << n1 << ' ' << n2 << endl;
    }
    return 0;
}
