#include<set>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

auto comp = [](vector<int> a, vector<int> b){
    for(int i = 0; i < a.size() && i < b.size(); i++){
        if(a[i] > b[i]) return true;
        else if(a[i] < b[i]) return false;
    }
    if(a.size() < b.size()) return false;
    else if(a.size() > b.size()) return true;
    return false;
};

int t,n;
vector<int> v;
set<vector<int>,decltype(comp)> s(comp);

void backtrack(int sum,int i, vector<int> l){
    if(sum == t){
        s.insert(l);
        return;
    }
    if(sum > t || i == n) return;
    backtrack(sum,i+1,l);
    sum += v[i];
    l.push_back(v[i]);
    backtrack(sum,i+1,l);
}

int main(){
    while(cin >> t >> n && (t||n)){
        v.resize(n);
        for(auto& x: v) cin >> x;
        s.clear();
        backtrack(0,0,vector<int>());
        cout << "Sums of "<<t<<":\n";
        if(s.empty()) cout << "NONE\n";
        else{
            for(auto x: s){
                for(int i = 0; i < x.size(); i++){
                    if(i) cout << '+';
                    cout << x[i];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
