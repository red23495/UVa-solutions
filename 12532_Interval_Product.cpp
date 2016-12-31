#include<iostream>
#include<vector>

using namespace std;

class tree{
    vector<char> t;
    vector<int> m;
    int n;
    int left(int i){return (i << 1);}
    int right(int i){return (i << 1)+1;}
    void build(int p, int L, int R){
        if(L == R){
            if(m[L] < 0) t[p] = -1;
            else if(m[L] > 0) t[p] = +1;
            else t[p] = 0;
            return;
        }
        build(left(p),L,(L+R)/2);
        build(right(p),(L+R)/2+1,R);
        t[p] = t[left(p)]*t[right(p)];
    }
    void update(int p, int L, int R, int i, int v){
        if(i > R || i < L) return;
        if(L == i && R == i){
            if(v < 0) t[p] = -1;
            else if(v > 0) t[p] = +1;
            else t[p] = 0;
        }
        else{
            update(left(p),L,(L+R)/2,i,v);
            update(right(p),(L+R)/2+1,R,i,v);
        }
        if(p != 1){
            int pp = p >> 1;
            int l = left(pp), r = right(pp);
            t[pp] = t[l]*t[r];
        }
    }
    char RMQ(int p, int L, int R,int i,int j){
        if(i > R || j < L) return 1;
        if(L >= i && R <= j) return t[p];
        return RMQ(left(p),L,(L+R)/2,i,j)*RMQ(right(p),(L+R)/2+1,R,i,j);
    }
public:
    tree(vector<int> a){
        m = move(a);
        n = m.size();
        t.assign(4*n,1);
        build(1,0,n-1);
        //for(auto x: t) cout << int(x) << ' '; cout << endl;
    }
    void update(int i, int v){
        update(1,0,n-1,i,v);
        //for(auto x: t) cout << int(x) << ' '; cout << endl;
    }
    char RMQ(int i, int j){
        return RMQ(1,0,n-1,i,j);
    }
};

int main(){
    int n,q;
    while(cin >> n >> q){
        vector<int> a;
        while(n--){
            int x;
            cin >> x;
            a.push_back(x);
        }
        tree t(a);
        while(q--){
            char c; int l,m;
            cin >> c >> l >> m;
            if(c == 'P') {
                char x = (int)t.RMQ(l-1,m-1);
                switch(x){
                case 0:
                    cout << '0';
                    break;
                case 1:
                    cout << '+';
                    break;
                case -1:
                    cout << '-';
                    break;
                }
            }
            else t.update(l-1,m);
        }
        cout << endl;
    }
    return 0;
}
