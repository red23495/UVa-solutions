#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,test;
    vector<vector<int>> v;
    cin >> test;
    while(test--){
        cin >> n;
        v.assign(n,vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> v[i][j];
                if(i > 0) v[i][j] += v[i-1][j];
                if(j > 0) v[i][j] += v[i][j-1];
                if(i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
            }
        }
        int m = -100*75*75;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        int x;
                        if(i <= k && j <= l){
                            x = v[k][l];
                            if(i > 0) x -= v[i-1][l];
                            if(j > 0) x -= v[k][j-1];
                            if(i > 0 && j > 0) x += v[i-1][j-1];
                        }
                        else if(i > k && j <= l){
                            int x1,x2;
                            x1 = v[n-1][l];
                            if(i > 0) x1 -= v[i-1][l];
                            if(j > 0) x1 -= v[n-1][j-1];
                            if(i > 0 && j > 0) x1 += v[i-1][j-1];
                            x2 = v[k][l];
                            if(j > 0) x2 -= v[k][j-1];
                            x = x1+x2;
                        }
                        else if(i <= k && j > l){
                            int x1,x2;
                            x1 = v[k][n-1];
                            if(i > 0) x1 -= v[i-1][n-1];
                            if(j > 0) x1 -= v[k][j-1];
                            if(i > 0 && j > 0) x1 += v[i-1][j-1];
                            x2 = v[k][l];
                            if(i > 0) x2 -= v[i-1][l];
                            x = x1+x2;
                        }
                        else{
                            int x1,x2,x3,x4;
                            x1 = v[k][l];
                            x2 = v[n-1][l];
                            if(i > 0) x2 -= v[i-1][l];
                            x3 = v[k][n-1];
                            if(j > 0) x3 -= v[k][j-1];
                            x4 = v[n-1][n-1];
                            if(i > 0) x4 -= v[i-1][n-1];
                            if(j > 0) x4 -= v[n-1][j-1];
                            if(i > 0 && j > 0) x4 += v[i-1][j-1];
                            x = x1+x2+x3+x4;
                        }
                        m = max(m,x);
                    }
                }
            }
        }
        cout << m << endl;
    }
    return 0;
}
