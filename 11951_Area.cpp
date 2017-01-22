#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(){
    int test;
    cin >> test;
    for(int t = 1; t <= test; t++){
        int r,c,K;
        cin >> r >> c >> K;
        vector<vector<ll>> v(r,vector<ll>(c));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int x;
                cin >> x;
                if(i > 0) x += v[i-1][j];
                if(j > 0) x += v[i][j-1];
                if(i > 0 && j > 0) x -= v[i-1][j-1];
                v[i][j] = x;
            }
        }
        int area = 0;
        int cost = K;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                for(int k = i; k < r; k++){
                    for(int l = j; l < c; l++){
                        int a = (k-i+1)*(l-j+1);
                        ll c = v[k][l];
                        if(i > 0)c -= v[i-1][l];
                        if(j > 0)c -= v[k][j-1];
                        if(i > 0 && j > 0) c += v[i-1][j-1];
                        if(a > area && c <= K){
                            area = a;
                            cost = c;
                        }
                        else if(a == area && c < cost) cost = c;
                    }
                }
            }
        }
        if(area == 0) cost = 0;
        cout << "Case #" << t << ": " << area << ' ' << cost << endl;
    }
    return 0;
}
