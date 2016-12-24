#include<iostream>
#include<vector>

using namespace std;

class fenwick_tree{
    vector<int> a,t;
    int lsbit(int i){return (i & (-i));}
    void build(){
        for(int i = 0; i < a.size(); i++){
            update(i,a[i]);
        }
    }
    int sum(int i){
        i++;int s = 0;
        while(i){
            s+=t[i];
            i -= lsbit(i);
        }
        return s;
    }
public:
    fenwick_tree(vector<int> v){
        a = move(v);
        t.assign(a.size()+1,0);
        build();
    }
    void update(int i, int inc){
        int j = i+1;
        while(j < t.size()){
            t[j]+=inc;
            j += lsbit(j);
        }
    }
    int sum(int i, int j){
        return sum(j) - sum(i);
    }
};
