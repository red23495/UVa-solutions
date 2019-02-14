#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned int uint;


int main(){
    uint a,b;
    while(cin >> a >> b){
        cout << (a^b) << endl;
    }
    return 0;
}
