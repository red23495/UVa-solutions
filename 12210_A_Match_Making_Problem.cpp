#include<iostream>

using namespace std;

int main(){
    int test = 0;
    int b,s;
    while(cin >> b >> s && (b||s)){
        cout << "Case " << ++test << ": ";
        int _min = 61;
        for(int i = 0; i < b; i++){
            int x;
            cin >> x;
            if(x < _min) _min = x;
        }
        for(int i = 0; i < s; i++) {
            int x; cin >> x;
        }
        if(b <= s) cout << "0\n";
        else{
            cout << (b - s) << ' ' << _min << endl;
        }
    }
    return 0;
}
