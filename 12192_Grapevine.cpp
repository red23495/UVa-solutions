#include<iostream>
#include<vector>

using namespace std;

int m,n,a,b;
vector<vector<int>> v;

int search_lo(int i,int l,int r,int k){
    if(l > r ){
        if(r < 0)return 0;
        else return r;
    }
    int mid = (l+r)/2;
    if(v[i][mid] == k) {
        while(mid+1 < n && v[i][mid+1] == k) mid++;
        return mid;
    }
    if(v[i][mid] > k) return search_lo(i,l,mid-1,k);
    return search_lo(i,mid+1,r,k);
}

int search_hi(int i,int l,int r,int k){
    if(l > r ){
        if(l >= n)return n-1;
        else return l;
    }
    int mid = (l+r)/2;
    if(v[i][mid] == k) {
        while(mid-1 >= 0 && v[i][mid-1] == k) mid--;
        return mid;
    }
    if(v[i][mid] > k) return search_hi(i,l,mid-1,k);
    return search_hi(i,mid+1,r,k);
}

bool check(int r, int c){
    return (r < m && v[r][c] <= b && v[r][c] >= a);
}

int main(){
    while(cin >> m >> n && m && n){
        v.assign(m,vector<int>(n));
        for(auto &x: v) for(auto &y : x) cin >> y;
        int q;
        cin >> q;
        while(q--){
            cin >> a >> b;
            int max = 0;
            for(int i = 0; i < m; i++){
                int l = search_hi(i,0,n-1,a);
                int h = search_lo(i,0,n-1,b);
                int dist = h - l+1;
                //cout << l << ' ' << h << ' ' << dist << ' ';
                for(int c = h;dist > max; dist--,h--){
                    if(check(i+dist-1,h)) max = dist;
                }
                //cout << max << endl;
            }
            cout << max << endl;
        }
        cout << "-\n";
    }
    return 0;
}
