#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
int v,e;
vector<vector<int>> g;
int _max;
bitset<101> maxc;
void backtrack(int i, bitset<101> c){
    if(i == v){
        int x = c.count();
        if(x > _max){
            _max = x;
            maxc = c;
        }
        return;
    }
    backtrack(i+1,c);
    bool check = true;
    for(auto x: g[i]){
        if(c[x]){
            check = false;
            break;
        }
    }
    c[i] = 1;
    if(check) backtrack(i+1,c);
}

int main(){
    int test;
    cin>>test;
    while(test--){
        _max = 0;
        maxc = 0;
        g.clear();
        cin >> v >> e;
        g.resize(v);
        while(e--){
            int a , b;
            cin >> a >> b;
            a--,b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        backtrack(0,bitset<101>());
        cout << _max << endl;
        for(int i = 0, j = 0; i < 101 && j < _max; i++){
            if(maxc[i]){
                cout << i+1;
                j++;
                if(j != _max) cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
