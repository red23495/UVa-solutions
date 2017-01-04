#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int abs(int n){return (n < 0)?-n:n;}

int main(){
    int n;
    while(cin >> n){
        vector<vector<int>> v(n,vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;
                v[i][j] = c - '0';
            }
        }
        int dist = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][j] == 1){
                    int md = numeric_limits<int>::max();
                    for(int k = 0; k < n; k++){
                        for(int l = 0; l < n; l++){
                            if(v[k][l] == 3){
                                int d = abs(i - k) + abs(j - l);
                                if(d < md) md = d;
                            }
                        }
                    }
                    if(dist < md) dist = md;
                }
            }
        }
        cout << dist << endl;
    }
    return 0;
}
