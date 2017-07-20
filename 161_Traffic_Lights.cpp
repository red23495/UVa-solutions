#include<bits/stdc++.h>

using namespace std;

int main(){
    constexpr int mx = 5*60*60;
    vector<int> signals;
    vector<int> green;
    while(true){
        int n;
        signals.clear();
        while(cin >> n && n != 0) {
            signals.push_back(n);
        }
        //cout << 'h';
        if(!signals.size() || signals[0] == 0) break;
        green.clear();green.resize(mx+1);
        for(int i = 0; i < signals.size(); i++){
            for(int j = 0; j <= mx; j+=(signals[i]*2)){
                for(int k = 0; k < signals[i]-5; k++){
                    if(j+k < green.size())green[j+k]++;
                }
            }
        }
        int ans = 0;
        int c = 0;
        while(green[c] == signals.size()) c++;
        for(int i = c; i < green.size(); i++){
            if(green[i] == signals.size()) {
                ans = i;
                break;
            }
        }
        if(!ans) cout << "Signals fail to synchronise in 5 hours\n";
        else{
            int second = ans%60;
            int minute = ans/60;
            int hour = minute/60;
            minute = minute%60;
            cout << setw(2) << setfill('0')<< hour << ':' << setw(2) << setfill('0')<< minute << ':' <<setw(2) << setfill('0')<< second << '\n' ;
        }
    }
    return 0;
}
