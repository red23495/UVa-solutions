#include<iostream>
#include<vector>
using namespace std;

int m,n,u,l;
vector<int> v;
bool fill(int x){
    int cur = 0, c = 0;
    for(int i = 0; i < v.size() && c < n; i++){
        if(cur + v[i] <= x) cur += v[i];
        else {
            c++;
            cur = v[i];
        }
    }
    if(c < n) return true;
    return false;
}
int main(){
    while(cin >> m >> n){
        v.resize(m);
        u = 0; l = 0;
        for(auto& x: v){
            cin >> x;
            if(x > l) l = x;
            u+=x;
        }
        int ans;
        while(u >= l){
            int mid = (l+u)/2;
            if(fill(mid)){
                ans = mid;
                u = mid-1;
            }
            else l = mid+1;
        }
        cout << ans << endl;
    }
    return 0;
}
