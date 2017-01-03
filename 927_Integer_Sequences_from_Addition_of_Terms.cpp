#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i <= n; i++){
            long long x;
            cin >> x;
            v.push_back(x);
        }
        int d;
        cin >> d;
        int k;
        cin >> k;
        int s = 1;
        while(((s*s)+s)/2*d < k) s++;
        long long sum = 0;
        for(int x = 0; x < v.size(); x++){
            long long ll = 1;
            for(int i = 0; i < x; i++) ll*=s;
            sum += v[x] * ll;
        }
        cout << sum << endl;
    }
    return 0;
}
