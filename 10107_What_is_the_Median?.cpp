#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v;
    int x;
    while(cin >> x){
        v.push_back(x);
        sort(v.begin(),v.end());
        if(v.size() % 2){
            cout << v[v.size()/2] << endl;
        }
        else{
            cout << (v[v.size()/2]+v[(v.size()/2)-1])/2 << endl;
        }
    }
    return 0;
}
