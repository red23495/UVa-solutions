#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> v,w,t,tw;
long long n,iw,dw;

int main(){
    int test;
    cin >> test;
    for(int te = 1; te <= test; te++){
        cin >> n;
        v.resize(n);
        w.resize(n);
        t.resize(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) cin >> w[i];
        t.assign(w.begin(),w.end());
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(v[i] > v[j]){
                    t[i] = max(t[i],t[j]+w[i]);
                }else if(v[i] == v[j]){
                    t[i] = max(t[i],t[j]);
                }
            }
        }
        iw = dw = 0;
        for(int i = 0; i < n; i++){
            iw = max(iw,t[i]);
        }
        t.assign(w.begin(),w.end());
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(v[i] < v[j]){
                    t[i] = max(t[i],t[j]+w[i]);
                }
                else if(v[i] == v[j]){
                    t[i] = max(t[i],t[j]);
                }
            }
        }
        for(int i = 0; i < n; i++){
            dw = max(dw,t[i]);
        }
        cout << "Case "<<te<<". ";
        if(iw >= dw) cout << "Increasing ("<<iw<<"). Decreasing ("<<dw<<").\n";
        else cout << "Decreasing ("<<dw<<"). Increasing ("<<iw<<").\n";
    }
    return 0;
}
