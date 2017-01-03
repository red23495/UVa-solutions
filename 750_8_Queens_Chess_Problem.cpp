#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int a,b,line;
vector<int> row(8);
vector<vector<int>> ans;

bool check(int r, int c){
    if(row[c]) return false;
    for(int i = 0; i < 8; i++){
        if(row[i] && abs(r-row[i]+1) == abs(c-i)) return false;
    }
    return true;
}

void backtrack(int r){
    if( r == a) {
        backtrack(r+1);
        return;
    }
    if(r == 8){
        ans.push_back(row);
        return;
    }
    for(int i = 0; i < 8; i++){
        if(check(r,i)){
            row[i] = r+1;
            backtrack(r+1);
            row[i] = 0;
        }
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        ans.clear();
        ans.reserve(100);
        cin >> a >> b;
        a--;b--;
        row[b] = a+1;
        backtrack(0);
        row[b] = 0;
        cout <<"SOLN       COLUMN\n";
        cout <<" #      1 2 3 4 5 6 7 8\n\n";
        auto x = [](vector<int> a, vector<int> b)->bool{
            for(int i = 0; i < 8; i++){
                if(a[i] < b[i]) return true;
                else if(a[i] > b[i]) return false;
            }
            return false;
        };
        sort(ans.begin(),ans.end(),x);
        for(int j = 0; j < ans.size(); j++){
            cout << setw(2) << ++line << "     ";
            for(int i = 0; i < 8; i++) cout << ' ' << ans[j][i]; cout << endl;
        }
        row.clear();
        row.resize(8);
        line = 0;
        if(test) cout << endl;
    }
    return 0;
}
