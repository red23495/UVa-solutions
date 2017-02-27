#include<bits/stdc++.h>

using namespace std;

int a,b;
int v[101][101];

int main(){
    int test = 1;
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    while(cin >> a >> b && a){
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                v[i][j] = INT_MAX;
            }
        }
        v[a][b] = 1;
        while(cin >> a >> b && a) v[a][b] = 1;
        for(int k = 1; k <= 100; k++){
            for(int i = 1; i <= 100; i++){
                for(int j = 1; j <= 100; j++){
                    if(v[i][k] == INT_MAX || v[k][j] == INT_MAX) continue;
                    v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
                    //cout << v[i][j]<< ' ' << i << ' ' << j << endl;
                }
            }
        }int cnt = 0, sum = 0;
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <=100; j++){
                if(i == j || v[i][j] == INT_MAX) continue;
                sum += v[i][j];
                cnt++;
            }
        }
        double ans = double(sum)/double(cnt);
        cout << "Case "<<test++<<": average length between pages = "<<fixed<<setprecision(3)<<ans<<" clicks\n";
    }
    return 0;
}
