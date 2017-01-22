#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v,t,r;

int search(int l, int r, int m){
    if(l > r) return l;
    int mid = (l+r)/2;
    if(v[t[mid]] == m) return mid;
    if(v[t[mid]] < m) return search(mid+1,r,m);
    return search(l,mid-1,m);
}

int main(){
    int x;
    while(cin>>x) v.push_back(x);
    r.assign(v.size(),-1);
    t.assign(1,0);
    for(int i = 1; i < v.size(); i++){
        if(v[i] > v[t[t.size()-1]]) {
            r[i] = t[t.size()-1];
            t.push_back(i);
        }
        else{
            if(v[i] < v[t[0]]) t[0] = i;
            else {
                int in = search(1,t.size()-1,v[i]);
                //cout << in << endl;
                t[in] = i;
                r[i] = t[in-1];
            }
        }
        //for(auto x: t) cout << v[x] << ' ' ; cout << endl;
    }
    cout << t.size() << "\n-\n";
    int i = t[t.size()-1];
    vector<int> ans;
    ans.reserve(t.size());
    while(i != -1){
        ans.push_back(v[i]);
        i = r[i];
    }
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << endl;
    return 0;
}
