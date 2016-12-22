#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,t,m;

struct r{
    int id;
    int time;
};
vector<r> result;
void pass(bool &_left, queue<r> &left, queue<r> &right, int &time){
    vector<r> ferry;
    while(ferry.size() < n && !left.empty() && left.front().time <= time){
        ferry.push_back(left.front());
        left.pop();
    }
    if(ferry.empty() && !right.empty() && right.front().time <= time){
        time+=t;
        _left = !_left;
    }
    else if(ferry.empty()){
        time++;
    }
    else{
        time+=t;
        _left = !_left;
        for(int i = 0; i < ferry.size(); i++){
            ferry[i].time = time;
            result.push_back(ferry[i]);
        }
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> t >> m;
        queue<r> left,right;
        int id = 0;
        while(m--){
            int p; string d;
            cin >> p >> d;
            if(d[0] == 'l') left.push({id++,p});
            else right.push({id++,p});
        }
        int time = 0;
        bool _left = true;
        while(!left.empty() || !right.empty()){
            if(_left) pass(_left,left,right,time);
            else pass(_left,right,left,time);
        }
        sort(result.begin(),result.end(),[](r x, r y){return x.id < y.id;});
        for(auto x: result) cout << x.time << endl;
        if(test) cout << endl;
        result.clear();
    }
    return 0;
}
