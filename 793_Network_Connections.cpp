#include<iostream>
#include<vector>
#include<string>
#include<sstream>
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
    void _union(int x, int y){
        int a = find(x), b = find(y);
        if(a == b) return ;
        if(rank[a] > rank[b]){
            p[b] = a;
        }else{
            p[a] = b;
            if(rank[a] == rank[b]) rank[b]++;
        }
    }
    int find(int n){
        if(p[n] == n) return n;
        else{
            int x = find(p[n]);
            p[n] = x;
            return x;
        }
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        int pc ;
        cin >> pc;
        u_set set(pc);
        while(cin.peek() == 10) cin.ignore();
        string s;
        int correct = 0, incorrect = 0;
        while(getline(cin,s) && s != ""){
            stringstream ss(s);
            char c; int a,b;
            ss >> c >> a >> b;
            a--;b--;
            if(c == 'c'){
                set._union(a,b);
            }
            else{
                if(set.find(a) == set.find(b)){
                    correct++;
                }
                else incorrect++;
            }
        }
        cout << correct << ',' << incorrect << endl;
        if(t) cout << endl;
    }
}
