#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int set;
    cin >> set;
    while(set--){
        int n,s,q,total = 0;
        cin >> n >> s >> q;
        vector<queue<int>> v(n);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            total+=x;
            for(int j = 0; j < x; j++){
                int p;
                cin >> p;
                v[i].push(p);
            }
        }
        stack<int> cargo;
        int time = 0;
        int current = 0;
        while(total){
            while(!cargo.empty() && cargo.top() == (current+1)){
                cargo.pop(); total--; time++;
            }
            while(v[current].size() < q && !cargo.empty()){
                if(cargo.top() != (current+1)){
                    int t = cargo.top();
                    v[current].push(t);
                    cargo.pop();
                    time++;
                }
                while(!cargo.empty() && cargo.top() == (current+1)){
                    cargo.pop(); total--; time++;
                }
            }
            while(cargo.size() < s && !v[current].empty()){
                int x = v[current].front();
                cargo.push(x);
                v[current].pop();
                time++;
            }
            if(total) time += 2;
            current = (current+1)%n;
        }
        cout << time << endl;
    }
    return 0;
}
