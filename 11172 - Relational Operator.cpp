#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

int main(){
    FASTIO
    int test;
    cin >> test;
    while(test--){
        int a,b;
        cin >> a >> b;
        if(a < b) cout << "<\n";
        else if(a == b) cout << "=\n";
        else cout << ">\n";
    }
    return 0;
}
