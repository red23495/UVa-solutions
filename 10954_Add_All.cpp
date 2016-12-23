#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        priority_queue<int,vector<int>,greater<int>> q;
        while(n--){
            int x;
            cin >> x;
            q.push(x);
        }
        int total = 0;
        while(q.size() > 1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            total += (x+y);
            q.push(x+y);
        }
        cout << total << endl;
    }
    return 0;
}
