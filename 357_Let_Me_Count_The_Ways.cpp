#include<bits/stdc++.h>

using namespace std;

unsigned long long arr[30001];
int coin[5] = {1,5,10,25,50};

int main(){
    arr[0] = 1;
    for(int i = 0; i < 5; i++){
        for(int j = coin[i]; j < 30001; j++){
            arr[j] += arr[j-coin[i]];
        }
    }
    int x;
    while(cin >> x){
        if(arr[x] == 1) cout << "There is only 1 way to produce "<<x<<" cents change.\n";
        else cout << "There are "<<arr[x]<<" ways to produce "<<x<<" cents change.\n";
    }
    return 0;
}
