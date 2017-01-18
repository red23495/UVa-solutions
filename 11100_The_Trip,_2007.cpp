#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
using namespace std;

int main(){
    int n;
    bool start = true;
    while(cin >> n && n){
        if(start) start = false;
        else cout << endl;
        vector<int> v(n);
        map<int,int> m;
        int _max = 0;
        for(auto& x: v){
            cin >> x;
            m[x]++;
            if(m[x] > _max) _max = m[x];
        }
        sort(v.begin(),v.end());
        vector<vector<int>> ans(_max);
        for(int i = 0; i < n; i++){
            ans[i%_max].push_back(v[i]);
        }
        cout << _max << endl;
        for(int i = 0; i < _max; i++){
            for(int j = 0; j < ans[i].size(); j++){
                if(j) cout << ' ';
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
