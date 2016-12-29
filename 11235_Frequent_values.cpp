#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class tree{
    vector<int> m,p,t;
    int n;
    int left(int i){return (i << 1);}
    int right(int i){return (i<<1)+1;}
    void build(int P, int L, int R){
        if(L == R){
            t[P] = p[L];
        }
        else{
            int i = left(P), j = right(P);
            build(i,L,(L+R)/2);
            build(j,(L+R)/2+1,R);
            t[P] = (t[i] > t[j])?t[i]:t[j];
        }
    }
    int RMQ(int P, int L, int R,int i ,int j){
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return t[P];
        return max(RMQ(left(P),L,(L+R)/2,i,j),RMQ(right(P),(L+R)/2+1,R,i,j));
    }
public:
    tree(int i){
        n = i;
        m.resize(n);
        p.resize(n);
        t.assign(4*n,0);
    }
    int& operator [] (int i){return m[i];}
    void build(){
        map<int,int> M;
        for(int i = 0; i < m.size(); i++){
            M[m[i]]++;
        }
        for(int i = 0; i < m.size();i++){
            p[i] = M[m[i]];
        }
        build(1,0,p.size()-1);
    }
    int RMQ(int i , int j){
        if(m[i] == m[j]) return (j - i)+1;
        int x = RMQ(1,0,n-1,i,j);
        if(p[i] == x || p[j] == x){
            int c1 = 0, c2 = 0;
            for(int a = i; m[a] == m[i] && p[a] == x && a <= j; a++)
                c1++;
            for(int a = j; m[a] == m[j] && p[a] == x && a >= i; a--)
                c2++;
            int M = max(c1,c2);
            if(M == x) return x;
            else{
                int a = RMQ(i+c1,j-c2);
                if(a > M) return a;
                else return M;
            }
        }
        return x;
    }
};

int main(){
    int n, q;
    while(cin >> n >> q && n){
        tree t(n);
        for(int i = 0; i < n; i++){
            cin >> t[i];
        }
        t.build();
        while(q--){
            int a,b;
            cin >> a >> b;
            a--;b--;
            cout << t.RMQ(a,b) << endl;
        }
    }
    return 0;
}
