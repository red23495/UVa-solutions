#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

vector<int> coins;
int mem[105][50005];

int knapsack(int index, int weight){
    //cout << index << ' ' << weight <<endl;
    if(index >= coins.size()) return 0;
    if(weight <= 0) return mem[index][weight] = 0;
    if(mem[index][weight] >= 0) return mem[index][weight];
    if(coins[index] > weight) mem[index][weight] = knapsack(index+1,weight);
    else mem[index][weight] = max(coins[index]+knapsack(index+1,weight-coins[index]),knapsack(index+1,weight));
    //cout << index << ' ' << weight << ' ' <<mem[index] << endl;
    return mem[index][weight];
}

int main(){
    FASTIO
    int test;
    cin >> test;
    while(test--){
        int n,sum = 0;
        cin >> n;
        coins.clear();
        coins.resize(n);
        memset(mem, -1, sizeof mem);
        for(int i = 0; i < n; i++){
            cin >> coins[i];
            sum += coins[i];
        }
        int val = knapsack(0,sum/2);
        //for(int i = 0; i < n; i++) cout << mem[i] << ' '; cout << endl;
        //cout <<  sum << ' ' <<val << endl;
        cout << (sum - 2*val) << endl;
    }
    return 0;
}
