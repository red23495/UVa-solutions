#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int k;
        cin >> k;
        vector<string> a(6),b(6);
        for(auto& s: a) cin >> s;
        for(auto& s: b) cin >> s;
        vector<vector<char>> common(5);
        for(int i = 0; i < 5; i++){
            map<char,bool> m;
            for(auto l: a) m[l[i]] = true;
            for(auto l: b) {
                if(m[l[i]]){
                    common[i].push_back(l[i]);
                    m[l[i]] = false;
                }
            }
            sort(common[i].begin(),common[i].end());
            //for(auto l: common[i]) cout << l; cout << endl;
        }
        long long p = common[0].size()*common[1].size()*common[2].size()*common[3].size()*common[4].size();
        if(p < k || p == 0) cout << "NO\n";
        else{
            char arr[6];
            int x = k-1;
            for(int i = 4; i >= 0; i--){
                arr[i] = common[i][x%common[i].size()];
                x /= common[i].size();
            }
            arr[5] = 0;
            cout << arr << endl;
        }
    }
    return 0;
}
