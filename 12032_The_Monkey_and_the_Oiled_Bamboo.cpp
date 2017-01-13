#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

bool climb(int strength){
    int last = 0;
    for(int i = 0; i < v.size() && strength >= 0; i++){
        if(v[i] - last > strength) return false;
        if(v[i] - last == strength) strength--;
        last = v[i];
    }
    if(strength >= 0) return true;
    return false;
}


int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        int n;
        cin >> n;
        v.resize(n);
        for(auto& x: v) cin >> x;
        int l = 0, u = v[n-1], ans = 0;
        while(l <= u){
            int mid = (l+u)/2;
            if(climb(mid)){
                u = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        cout << "Case "<< i << ": " << ans << endl;
    }
}
