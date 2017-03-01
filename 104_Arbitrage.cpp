#include<bits/stdc++.h>

using namespace std;

int n;
double table[20][20],v[21][21][21];
int p[21][21][21];
vector<int> path;
void print_path(int i, int j, int s){
    if(s) print_path(i,p[i][j][s],s-1);
    path.push_back(j);
}

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) table[i][j] = -1.00;
                else cin >> table[i][j];
                for(int k = 0; k <= n; k++){
                    if(!k && i == j) v[i][j][0] = 1.00;
                    else if(i != j && k == 1) v[i][j][1] = table[i][j];
                    else v[i][j][k] = 0.00;
                    p[i][j][k] = i;
                }
            }
        }
        for(int s = 1;  s<=n; s++){
            for(int k = 0; k < n; k++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        //cout << i << ' ' << j << ' ' << k <<':' << endl;
                        if(k == j) continue;
                        double c = v[i][k][s-1]*table[k][j];
                        //cout << s << ' ' << v[i][k][s-1] << ' ' << table[k][j] << endl;
                        if(v[i][j][s] < c){
                            v[i][j][s] = c;
                            p[i][j][s] = k;
                        }
                    }
                }
            }
        }
        int x,y,l = n+1;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < l; j++){
                if(v[i][i][j] > 1.01){
                    x = i; y = i; l = j;
                }
            }
        }
        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << i << ' ' << j << ':';
                for(int k = 0; k <= n; k++){
                    cout << ' ' << v[i][j][k];
                }
                cout << endl;
            }
        }*/
        if(l > n) cout << "no arbitrage sequence exists\n";
        else{
            path.clear();
            print_path(x,y,l);
            for(int i = 0;i < path.size();i++){
                if(i) cout << ' ';
                cout << path[i]+1 ;
            }
            cout << endl;
        }
    }
    return 0;
}
