#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> coin(n);
        for(auto& x: coin) cin >> x;
        long long sum = 0;
        int count = 0;
        for(int i = 0; i < n-1; i++){
            if(sum+coin[i] < coin[i+1]){
                sum+=coin[i];
                count++;
            }
        }
        if(sum < coin[n-1]) count++;
        cout << count << endl;
    }
    return 0;
}
