#include<iostream>
#include<vector>
#include<cstdint>
#include<string>
#include<ctime>
using namespace std;

class tree{
    vector<int64_t> t;
    string m;
    vector<char> lp;
    int n;
    int left(int i){return i << 1;}
    int right(int i){return (i << 1)+1;}
    int buc(int64_t i){return i >> 20;}
    int bar(int64_t i){return (i << 44) >> 44;}
    void build(int p, int L, int R){
        if(L == R){
            if(m[L] == '0') t[p] = 1;
            else t[p] = (1 << 20);
            return;
        }
        int i = left(p), j = right(p);
        build(i,L,(L+R)/2);
        build(j,(L+R)/2+1,R);
        t[p] = t[i]+t[j];
    }
    void lazy(int p){
        int i = left(p),j = right(p);
        if(i < 4*n && lp[i]) lazy(i);
        if(j < 4*n && lp[j]) lazy(j);
        int bc = buc(t[p]), br = bar(t[p]);
        switch(lp[p]){
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
        if(i < 4*n && t[i]) lp[i] = lp[p];
        if(j < 4*n && t[j]) lp[j] = lp[p];
        lp[p] = 0;
    }
    void update(int p, int L, int R, int i, int j, char c){
        if(lp[p]) lazy(p);
        if(i > R || j < L) return;
        if(L >= i && R <= j){
            lp[p] = c;
            lazy(p);
        }else{
            update(left(p),L,(L+R)/2,i,j,c);
            update(right(p),(L+R)/2+1,R,i,j,c);
        }
        if(p != 1){
            int pp = p >> 1;
            int a = left(pp), b = right(pp);
            if(a < 4*n && lp[a]) lazy(a);
            if(b < 4*n && lp[b]) lazy(b);
            t[pp] = ((a < 4*n)?t[a]:0)+((b < 4*n)?t[b]:0);
        }
    }
    int64_t RMQ(int p, int L, int R, int i, int j){
        if(lp[p]) lazy(p);
        if(i > R || j < L) return 0;
        if(L >= i && R <= j) return t[p];
        return RMQ(left(p),L,(L+R)/2,i,j)+RMQ(right(p),(L+R)/2+1,R,i,j);
    }
public:
    tree(string s){
        n = s.length();
        t.resize(4*n);
        lp.resize(4*n);
        m = move(s);
        build(1,0,n-1);
    }
    void update(int i, int j, char c){
        update(1,0,n-1,i,j,c);
    }
    int RMQ(int i, int j){
        return buc(RMQ(1,0,n-1,i,j));
    }
};

int main(){
    int test;
    cin >> test;
    for(int x = 1; x <= test; x++){
        cout << "Case " << x << ":\n";
        int n;
        cin >> n;
        vector<int> l;
        vector<string> o;
        l.reserve(100);
        o.reserve(100);
        int c = 0;
        while(n--){
            int m; string s;
            cin >> m >> s;
            c += s.length()*m;
            l.push_back(m);
            o.push_back(s);
        }
        string str;
        str.reserve(c);
        for(int i = 0; i < l.size();i++){
            while(l[i]--){
                for(auto c: o[i]) str.push_back(c);
            }
        }
        tree t(str);
        int q,qc = 0;
        cin >> q;
        while(q--){
            char c; int a,b;
            cin >> c >> a >> b;
            if(c == 'S') cout << 'Q' << ++qc << ": " << t.RMQ(a,b) << endl;
            else t.update(a,b,c);
        }
    }
    return 0;
}
