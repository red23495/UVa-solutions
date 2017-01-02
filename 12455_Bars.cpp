#include<iostream>
#include<vector>
using namespace std;

bool possible(const vector<int>& v, int index, int sum, int val, bool& tracker){
    if(sum == val) {tracker = false; return true;}
    if(index == v.size()) return false;
    if(tracker)return possible(v,index+1,sum,val,tracker)||possible(v,index+1,sum+v[index],val,tracker);
    return false;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int l,n;
        cin >> l >> n;
        vector<int> v(n);
        for(auto& x: v) cin >> x;
        bool tracker = true;
        if(possible(v,0,0,l,tracker)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
