#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct query{
    int id;
    int period;
    int time;
    friend bool operator < (query x, query y);
};

bool operator < (query x, query y){
    return (x.time > y.time);
}

int main(){
    string s;
    priority_queue<query> q;
    while(cin >> s && s[0] != '#'){
        int id,time;
        cin >> id >> time;
        q.push({id,time,time});
    }
    int time = q.top().time;
    int n;
    cin >> n;
    vector<int> v;
    vector<query> t;
    while(v.size() != n){
        while(q.top().time == time && !q.empty()){
            t.push_back(q.top());
            q.pop();
        }
        sort(t.begin(),t.end(),[](query x, query y){return x.id < y.id;});
        for(int i = 0; i < t.size() && v.size() != n; i++){
            v.push_back(t[i].id);
            t[i].time += t[i].period;
            q.push(t[i]);
        }
        t.clear();
        time = q.top().time;
    }
    for(auto i: v){
        cout << i << endl;
    }
    return 0;
}
