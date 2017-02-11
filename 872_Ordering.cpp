#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int out[26],n;
bool printed;
void top_sort(vector<char>& p){
    if(p.size() == n){
        printed = true;
        for(int i = 0; i < n; i++){
            if(i) cout << ' ';
            cout << p[i];
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < 26; i++){
        if(out[i] == 0){
            out[i]--;
            for(auto& x: v[i]) out[x]--;
            p.push_back(i+'A');
            top_sort(p);
            p.pop_back();
            for(auto& x: v[i]) out[x]++;
            out[i]++;
        }
    }

}

int main(){
    int test;
    cin >> test;
    while(test--){
        memset(out,-1, sizeof out);
        v.clear();
        v.resize(26);
        string s; n = 0;printed = false;
        while(cin.peek() == 10) cin.ignore();
        getline(cin,s);
        stringstream ss(s);
        char a,b,c;
        while(ss >> c) {out[c-'A'] = 0;n++;}
        while(cin.peek() == 10) cin.ignore();
        getline(cin,s);
        stringstream ss2(s);
        while(ss2 >> a >> b >> c){
            v[a-'A'].push_back(c-'A');
            out[c-'A']++;
        }
        vector<char> p;
        top_sort(p);
        if(!printed) cout << "NO\n";
        if(test) cout << endl;
    }
    return 0;
}
