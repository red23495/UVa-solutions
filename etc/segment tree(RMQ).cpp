#include<iostream>
#include<vector>
using namespace std;

class segment_tree{
private:
    vector<int> a,t,lp;
    int n;
    int left(int p){ return p << 1;}
    int right(int p){ return (p<<1)+1;}
    void build(int parent, int L, int R){
        if(L == R){
            t[parent] = L;
        }
        else{
            build(left(parent),L,(L+R)/2);
            build(right(parent),((L+R)/2)+1,R);
            int p1 = t[left(parent)];int p2 = t[right(parent)];
            t[parent] = (a[p1] < a[p2])?p1:p2;
        }
    }
    void lazy(int p){
        if(t[p] != t[p>>1])a[t[p]] += lp[p];
        if(t[left(p)] != -1) lp[left(p)] += lp[p];
        if(t[right(p)] != -1) lp[right(p)] += lp[p];
        lp[p] = 0;
    }
    int RMQ(int p, int L, int R, int i, int j){
        if(lp[p]) lazy(p);
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return t[p];
        int p1 = RMQ(left(p),L,(L+R)/2,i,j);
        int p2 = RMQ(right(p),(L+R)/2+1,R,i,j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (a[p1] < a[p2])?p1:p2;
    }
    void update(int p, int L, int R, int i, int j, int inc){
        if(lp[p]) lazy(p);
        if(L > j || R < i) return;
        if(L >= i && R <= j){
            lp[p] = inc;
            lazy(p);
        }
        else{
            update(left(p),L,(L+R)/2,i,j,inc);
            update(right(p),(L+R)/2+1,R,i,j,inc);
        }if(p != 1){
            int pp = p >> 1;
            int p1 = p <<1, p2 = (p <<1)+1;
            t[pp] = (a[t[p1]] < a[t[p2]])?p1:p2;
        }
    }
public:
    segment_tree(vector<int> i){
        n = i.size();
        a = move(i);
        t.assign(4*n,-1);
        lp.resize(4*n,0);
        build(1,0,n-1);
    }
    int RMQ(int i, int j){
       return RMQ(1,0,n-1,i,j);
    }
    void update(int i, int j, int inc){
        update(1,0,n-1,i,j,inc);
    }
};
