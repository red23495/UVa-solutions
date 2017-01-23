#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v,t;
int n,m;

int search_hi(int l, int r, int x){
    if(l > r) return l;
    int mid = (l+r)/2;
    if(t[mid] < x) return search_hi(mid+1,r,x);
    else if(t[mid] > x) return search_hi(l,mid-1,x);
    return mid;
}

int search_lo(int l, int r, int x){
    if(l > r) return l;
    int mid = (l+r)/2;
    if(t[mid] > x) return search_lo(mid+1,r,x);
    else if(t[mid] < x) return search_lo(l,mid-1,x);
    return mid;
}

int lis(int in){
    t.clear();
    t.push_back(v[in]);
    for(int i = in+1; i < v.size(); i++){
        if(v[i] > t[t.size()-1]) t.push_back(v[i]);
        else if( v[i] > t[0]){
            int x = search_hi(1,t.size()-1,v[i]);
            if(x)t[x] = v[i];
        }
    }
    return t.size();
}

int lds(int in){
    t.clear();
    t.push_back(v[in]);
    for(int i = in+1; i < v.size(); i++){
        if(v[i] < t[t.size()-1]) t.push_back(v[i]);
        else if(v[i] < t[0]){
            int x = search_lo(1,t.size()-1,v[i]);
            if(x)t[x] = v[i];
        }
    }
    return t.size();
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        v.resize(n);
        for(auto& x: v) cin >> x;
        m = 0;
        for(int i = 0; i < n; i++){
            //cout << m << ' '<< i << ' '<< lds(i) <<' ' << lis(i) << endl;
            m = max(m,lds(i)+lis(i)-1);
        }
        cout << m << endl;
    }
}
