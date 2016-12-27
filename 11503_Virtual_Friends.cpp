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
    int find(int i){
        if(p[i] == i) return i;
        p[i] = find(p[i]);
        return p[i];
    }
    void _union(int x, int y){
        int a = find(x), b = find(y);
        if(a == b) return;
        if(rank[a] > rank[b]){
            p[b] = a;
            rank[a] += (rank[b]+1);
        }
        else{
            p[a] = b;
            rank[b] += (rank[a]+1);
        }
    }
    int network(int x){
        int p = find(x);
        return rank[p]+1;
    }
};

int main(){
    int test;
    cin >> test;
    while(test--){
        int x;
        cin >> x;
        map<string,int> m;
        int count = 0;
        u_set set(2*x);
        while(x--){
            string n1,n2;
            cin >> n1 >> n2;
            if(m.find(n1) == m.end()) m[n1] = count++;
            if(m.find(n2) == m.end()) m[n2] = count++;
            set._union(m[n1],m[n2]);
            cout << set.network(m[n1]) << endl;
        }
    }
}
