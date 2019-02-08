#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

struct Segment{
    int start;
    int end;
    bool operator < (Segment rhs) const{
        if(start < rhs.start) return true;
        else if(start == rhs.start) return (end > rhs.end);
        return false;
    }
};

vector<Segment> v;

int Fit(int covered, int begin, int& next){
    int next_cover = covered;
    int ret = -1;
    int i = begin;
    while(i < v.size() && v[i].start <= covered){
        if(next_cover < v[i].end){
            next_cover = v[i].end;
            ret = i;
        }
        i++;
    }
    next = i;
    if(covered == next_cover) return -1;
    return ret;
}

int main(){
    FASTIO
    int test;
    cin >> test;
    while(test--){
        int m;
        cin >> m;
        v.clear();
        int l,r;
        while(cin >> l >> r && !(!l && !r)){
            //cout << l << r << endl;
            v.push_back({l,r});
        }
        sort(v.begin(),v.end());
        //for(auto x: v){
        //    cout << x.start << ' ' << x.end << endl;
        //}
        int covered = 0;
        int start = 0;
        vector<int> ans;
        while(covered < m){
            int res = Fit(covered,start,start);
            if(res == -1) break;
            //cout << v[res].start << ' ' << v[res].end << endl;
            ans.push_back(res);
            covered = v[res].end;
        }
        if(covered < m) cout << "0\n";
        else {
            cout << ans.size() << endl;
            for(int i = 0; i < ans.size(); i++){
                cout << v[ans[i]].start << ' ' << v[ans[i]].end << endl;
            }
        }
        if(test) cout << endl;
    }
    return 0;
}

