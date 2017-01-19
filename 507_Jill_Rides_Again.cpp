#include<iostream>
#include<vector>
using namespace std;

int main(){
    int test;
    cin >> test;
    for(int a = 1; a <= test; a++){
        int n;
        cin >> n;
        int v[20005];
        for(int i = 0; i < n-1; i++) cin >> v[i];
        int sum = 0, ans = 0, l = 0, r = -1;
        int t = 0;
        for(int i = 0; i < n-1; i++){
            sum += v[i];
            if(sum >= ans){
                if((i - t) > (r - l) || sum > ans) {
                    l = t;
                    r = i;
                }
                ans = sum;
            }
            if(sum < 0) {
                t = i+1;
                sum = 0;
            }
        }
        if(ans)cout << "The nicest part of route "<<a<<" is between stops "<<l+1<<" and "<<r+2<<endl;
        else cout << "Route "<<a<<" has no nice parts\n";
    }
}
