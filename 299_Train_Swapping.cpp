#include<bits/stdc++.h>

using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n-i; j++){
                if(v[j-1] > v[j]){
                    int t = v[j];
                    v[j] = v[j-1];
                    v[j-1] = t;
                    cnt++;
                }
            }
        }
        cout << "Optimal train swapping takes "<< cnt <<" swaps.\n";
    }
    return 0;
}
