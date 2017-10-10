#include<bits/stdc++.h>

using namespace std;
//using ll = long long;
#define ll long long

int main(){
    vector<ll> cof;
    string s;
    while(getline(cin,s)){
        cof.clear();
        stringstream ss(s);
        ll n;
        while(ss>>n) cof.push_back(n);
        getline(cin,s);
        ss.str(s);
        ss.clear();
        bool start = true;
        while(ss >> n){
            ll x = 1;
            ll sum = cof[cof.size()-1];
            for(int i = cof.size()-2; i >= 0; i--){
                x *= n;
                sum += (cof[i]*x);
            }
            if(start){
                start = false;
            }else{
                cout << ' ';
            }
            cout << sum;
        }
        cout << endl;
    }
    return 0;
}
