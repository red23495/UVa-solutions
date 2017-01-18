#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int price[21][21];
int money[201][21];
int m,k;

int maximum(int left, int l){
    if(left < 0) return -1;
    if(l == k) return m-left;
    if(money[left][l] > -1) return money[left][l];
    int& ans = money[left][l];
    ans = -1;
    for(int i = 1; i <= price[l][0]; i++){
        ans = max(ans,maximum(left - price[l][i],l+1));
    }
    return ans;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> m >> k;
        for(int i = 0; i < k; i++){
            cin >> price[i][0];
            for(int j = 1; j <= price[i][0]; j++)
                cin >> price[i][j];
        }
        memset(money,-1,sizeof money);
        int ans = maximum(m,0);
        if(ans < 0) cout << "no solution\n";
        else cout << ans << endl;
    }
}
