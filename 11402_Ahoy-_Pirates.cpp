#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstdint>

using namespace std;

class tree{
    vector<int64_t> t;
    vector<queue<char>> lp = {};
    int64_t n;
    string s;
    int64_t left(int64_t i){return i << 1;}
    int64_t right(int64_t i){return (i << 1)+1;}
    int64_t buc(int64_t i){return i >> 20;}
    int64_t bar(int64_t i){return (i << 44)>>44;}
    void build(int64_t p, int64_t L, int64_t R){
        if(L == R){
            if(s[L] == '0') t[p] = 1;
            else t[p] = (1 << 20);
            return;
        }
        int64_t i = left(p),j = right(p);
        build(i,L,(L+R)/2);
        build(j,(L+R)/2+1,R);
        t[p] = t[i]+t[j];
    }
    void lazy(int64_t p){
        while(!lp[p].empty()){
            char c = lp[p].front();
            int64_t bc = buc(t[p]), br = bar(t[p]);
            switch(c){
            case 'F':
                t[p] = ((bc+br)<<20);
                break;
            case 'E':
                t[p] = (bc+br);
                break;
            case 'I':
                t[p] = (br<<20)+bc;
                break;
            }
            int64_t l = left(p), r = right(p);
            if(l < 4*n && !lp[l].empty()) lazy(l);
            if(r < 4*n && !lp[r].empty()) lazy(r);
            if(l < 4*n && t[l])lp[l].push(c);
            if(r < 4*n && t[r])lp[r].push(c);
            lp[p].pop();
        }
    }
    void update(int64_t p, int64_t L, int64_t R, int64_t i, int64_t j, char c){
        if(!lp[p].empty()) lazy(p);
        if(i > R || j < L) return;
        if(L >= i && R <= j){
            lp[p].push(c);
            lazy(p);
        }else{
            update(left(p),L,(L+R)/2,i,j,c);
            update(right(p),(L+R)/2+1,R,i,j,c);
        }
        if(p != 1){
            int64_t pp = p >> 1;
            int64_t x = left(pp), y = right(pp);
            if(!lp[x].empty()) lazy(x);
            if(!lp[y].empty()) lazy(y);
            t[pp] = t[x]+t[y];
        }
    }
    int64_t RMQ(int64_t p, int64_t L, int64_t R, int64_t i , int64_t j){
        if(!lp[p].empty()) lazy(p);
        if(i > R || j < L) return 0;
        if(L >= i && R <= j) return t[p];
        int64_t x = RMQ(left(p),L,(L+R)/2,i,j);
        int64_t y = RMQ(right(p),(L+R)/2+1,R,i,j);
        return x+y;
    }
public:
    tree(string& str){
        n = str.length();
        t.resize(4*n);
        lp.resize(4*n);
        s = move(str);
        build(1,0,n-1);
    }
    int64_t RMQ(int64_t i, int64_t j){
        return buc(RMQ(1,0,n-1,i,j));
    }
    void update(int64_t i, int64_t j, char c){
        update(1,0,n-1,i,j,c);
    }
};

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int64_t test;
    cin >> test;
    for(int64_t aa = 1; aa <= test; aa++){
        cout << "Case " << aa << ":\n";
        int64_t a,q;
        cin >> a;
        string str;
        str.reserve(1024000l);
        while(a--){
            int64_t m; string s;
            cin >> m >> s;
            while(m--){
                for(char c: s) str.push_back(c);
            }
        }
        if(str.length() > 1000000) throw -1;
        //cout << str;
        tree t(str);
        cin >> q;
        int64_t qc = 0;
        while(q--){
            char c; int64_t a,b;
            cin >> c >> a >> b;
            if(c == 'S') cout << 'Q' << ++qc << ": " << t.RMQ(a,b) << endl;
            else t.update(a,b,c);
        }
    }
}
