#include<iostream>
#include<vector>
using namespace std;

class union_find{
private:
    vector<int> p, rank;
public:
    union_find(int i){
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
};
