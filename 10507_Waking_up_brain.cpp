#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

class u_set{
    vector<int> p,rank;
public:
    u_set(int n){
        p.resize(n);
        rank.assign(n,0);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }
    int find(int n){
        if(p[n] == n) return n;
        int x = find(p[n]);
        p[n] = x;
        return x;
    }
    void _union(int x, int y){
        int a = find(x), b = find(y);
        if(a == b) return;
        if(rank[a] > rank[b]){
            p[b] = a;
        }
        else{
            p[a] = b;
            if(rank[a] == rank[b]) rank[b]++;
        }
    }
};

int main(){
    int n;
    while(cin >> n){
        map<char,int> m;
        u_set set(n);
        int q;
        cin >> q;
        int count = 0;
        char cc[3];
        cin >> cc[0] >> cc[1] >> cc[2];
        for(int i = 0; i < 3; i++){
            m[cc[i]] = count++;
            set._union(m[cc[0]],m[cc[i]]);
        }
        vector<string> com;
        while(q--){
            string s;
            cin >> s;
            if(m.find(s[0]) == m.end()) m[s[0]] = count++;
            if(m.find(s[1]) == m.end()) m[s[1]] = count++;
            com.push_back(s);
        }
        int time = 0;
        int last = 0;
        while(last != com.size() && !com.empty()){
            map<char,int> t;
            vector<string> s;
            vector<int> xx;
            for(int i = 0; i < com.size(); i++){
                auto x = com[i];
                if(set.find(m[x[0]]) == set.find(m[cc[0]])){
                    t[x[1]]++;
                    if(t[x[1]] > 2)xx.push_back(m[x[1]]);
                }
                else if(set.find(m[x[1]]) == set.find(m[cc[0]])){
                    t[x[0]]++;
                    if(t[x[0]] > 2)xx.push_back(m[x[0]]);
                }
            }
            for(auto x: xx){
                set._union(x,m[cc[0]]);
            }
            for(auto x: com){
                if(!(set.find(m[x[0]]) == set.find(m[cc[0]]) && set.find(m[x[1]]) == set.find(m[cc[0]])))
                    s.push_back(x);
            }
            last = com.size();
            com = move(s);
            time++;
        }
        if(com.empty() && (n == 3 || time != 0) ) cout << "WAKE UP IN, "<<time<<", YEARS\n";
        else cout << "THIS BRAIN NEVER WAKES UP\n";
    }
    return 0;
}
