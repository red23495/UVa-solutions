#include<bits/stdc++.h>

using namespace std;

class union_find{
private:
    vector<int> p, rank;
    int n;
public:
    union_find(int i){
        int n = i;
        p.resize(i);
        rank.assign(i,0);
        for(int i = 0; i < p.size();i++){
            p[i] = i;
        }
    }
    int find_set(int i){
        if(p[i] == i)
            return i;
        else{
            int x = find_set(p[i]);
            p[i] = x;
            return x;
        }
    }
    void union_set(int i, int j){
        int x = find_set(i), y = find_set(j);
        if(x != y){
            if(rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }

        }
    }
    int maximum(){
        //for(auto x: p) cout << x << ' ' ;cout << endl;
        vector<bool> t(p.size(),false);
        int m = 0;
        for(int i = 0; i < p.size(); i++){
            int X = find_set(i);
            if(!t[X]){
                m++;
                t[X] = true;
            }
        }
        return m;
    }
};
int main(){
    int test;
    cin >> test;
    for(int t = 0; t < test; t++){
        if(t) cout << endl;
        char c,d;
        int x;
        cin >> c;
        x = c-'A';
        x++;
        union_find u(x);
        if(cin.peek() == '\n') cin.ignore();
        string s;
        while(getline(cin,s,'\n') && s.length() != 0) u.union_set(s[0]-'A',s[1]-'A');
        cout << u.maximum() << endl;
    }
    return 0;
}
