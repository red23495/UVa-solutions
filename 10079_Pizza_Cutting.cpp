#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    while(cin >> n && n >= 0){
        ll ans;
        if(n==0) ans = 1;
        else if(n==1) ans = 2;
        else{
            ans = 2*n + ((n-2)*(n-1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}
