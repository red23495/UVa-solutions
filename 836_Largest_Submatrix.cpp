#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

vector<vector<int>> v;

int main(){
    //FASTIO
    int test;
    cin >> test;
    while(test--){
        v.clear();
        while(cin.peek() == 10) cin.ignore();
        string s;
        //cout << "STARTING";
        while(getline(cin,s) && s != ""){
            //cout << s << endl;
            vector<int> temp;
            for(int i = 0; i < s.length(); i++) temp.push_back((s[i] == '0')?0:1);
            v.push_back(temp);
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                if(i > 0) v[i][j] += v[i-1][j];
                if(j > 0) v[i][j] += v[i][j-1];
                if(i > 0 && j > 0) v[i][j] -= v[i-1][j-1];
                //cout << v[i][j] << ',';
            }
            //cout << endl;
        }
        int ans = 0;
        for(int i = 0; i < v.size(); i++) for(int j = 0; j < v[i].size(); j++){
            for(int k = i; k < v.size(); k++) for(int l = j; l < v[k].size(); l++){
                int x = v[k][l];
                if(i > 0) x -= v[i-1][l];
                if(j > 0) x -= v[k][j-1];
                if(i > 0 && j > 0) x += v[i-1][j-1];
                if(x == (k-i+1)*(l-j+1)){
                    ans = max(ans,x);
                    //cout << x << ' ' << i << ' ' << j << ' ' << k << ' ' << l << endl;
                }
            }
        }
        cout << ans << endl;
        if(test) cout << endl;
    }
    return 0;
}

