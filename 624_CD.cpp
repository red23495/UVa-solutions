#include<iostream>
#include<vector>

using namespace std;

int m,n;
vector<int> mc;
vector<int> tracks;
bool check;

void backtrack(int sum, int index, vector<int> l){
    //cout << sum << ' ' << index << endl;
    if(check || sum > n) return;
    if((n - sum) < (n-m) && (n-sum) >= 0){
        m = sum;
        mc = l;
    }
    if(n == m) {check = true; return;}
    if(index >= tracks.size()) return;
    backtrack(sum,index+1,l);
    sum += tracks[index];
    l.push_back(tracks[index]);
    backtrack(sum,index+1,l);
    //backtrack(sum,index+2,l);
}

int main(){
    int t;
    while(cin >> n >> t){
        m = 0;
        mc.clear();
        check = false;
        tracks.resize(t);
        for(int& x: tracks){
            cin >> x;
        }
        backtrack(0,0,vector<int>());
        for(int i: mc) cout << i << ' ';
        cout <<"sum:"<<m<<endl;
    }
    return 0;
}
