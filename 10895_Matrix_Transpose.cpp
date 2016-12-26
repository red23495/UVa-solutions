#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct id{
    int col;
    int val;
    friend bool operator > (id x, id y){
        return (x.col > y.col);
    }
};

int main(){
    int m,n;
    while(cin >> m >> n){
        vector<priority_queue<id,vector<id>,greater<id>>> mat(n);
        for(int i = 0; i < m ; i++){
            int x;
            cin >> x;
            vector<int> p;
            for(int j = 0; j < x; j++){
                int y;
                cin >> y;
                y--;
                p.push_back(y);
            }
            for(int j = 0; j < x; j++){
                int y;
                cin >> y;
                mat[p[j]].push(id{i,y});
            }
        }
        cout << n << ' ' << m << endl;
        for(int i = 0; i < n; i++){
            cout << mat[i].size();
            vector<int> out;
            while(!mat[i].empty()){
                auto x = mat[i].top();
                mat[i].pop();
                out.push_back(x.val);
                cout << ' ' << x.col+1;
            }
            cout << endl;
            for(int i = 0; i < out.size();i++){
                if(i != 0) cout << ' ';
                cout << out[i];
            }
            cout << endl;
        }
    }
    return 0;
}
