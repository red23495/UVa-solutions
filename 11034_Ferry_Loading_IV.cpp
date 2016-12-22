#include<iostream>
#include<queue>

using namespace std;
int l ;
void pass(bool &dir, queue<int> &from, queue<int> &to, int &turn){
    int ferry = 0;
    while(!from.empty() && from.front()+ferry <= l*100){
        ferry+= from.front();
        from.pop();
    }
    dir = !dir;
    turn++;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int m;
        cin >> l >> m;
        queue<int> left,right;
        while(m--){
            int x; string s;
            cin >> x >> s;
            if(s[0] == 'l') left.push(x);
            else right.push(x);
        }
        bool _left = true;
        int turn = 0;
        while(!left.empty() || !right.empty()){
            if(_left) pass(_left,left,right,turn);
            else pass(_left,right,left,turn);
        }
        cout << turn << endl;
    }
    return 0;
}
