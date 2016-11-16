#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        char s;
        double r,c;
        cin >> s >> r >> c;
        switch(s){
        case 'r':
        case 'Q':
            cout << ((r < c)? r:c) ;
            break;
        case 'k':
            cout << int(ceil((r*c)/2));
            break;
        case 'K':
            cout << int(ceil(r/2)*ceil(c/2));
            break;
        }
        cout << endl;
    }
    return 0;
}
