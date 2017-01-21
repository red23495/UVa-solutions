#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

using ll = long long;

int main(){
    int test;
    cin >> test;
    ll v[20][20][20];
    int a,b,c; ll m;
    while(test--){
        cin >> a >> b >> c;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    ll x;
                    cin >> x;
                    if( j > 0) x += v[i][j-1][k];
                    if( k > 0) x += v[i][j][k-1];
                    if(j > 0 && k > 0) x -= v[i][j-1][k-1];
                    v[i][j][k] = x;
                }
            }
        }
        m = numeric_limits<ll>::min();
        for(int i = 0; i < b; i++){
            for(int j = 0; j < c; j++){
                for(int k = i; k < b; k++){
                    for(int l = j; l < c; l++){
                        ll arr[20];
                        for(int p = 0; p < a; p++){
                            ll x = v[p][k][l];
                            if(i > 0) x-= v[p][i-1][l];
                            if(j > 0) x-= v[p][k][j-1];
                            if(i > 0 && j > 0) x += v[p][i-1][j-1];
                            arr[p] = x;
                            if(p > 0) arr[p] += arr[p-1];
                        }
                        //for(int p= 0; p < a; p++) cout << arr[p] << endl; cout << endl;
                        for(int p = 0; p < a; p++){
                            for(int n = p; n < a; n++){
                                ll x = arr[n];
                                if(p > 0) x -= arr[p-1];
                                m = max(m,x);
                            }
                        }
                    }
                }
            }
        }
        cout << m << endl;
        if(test) cout << endl;
    }
    return 0;
}
