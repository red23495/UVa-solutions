#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

#define GET_TEST 0
#define GET_SAMPLE 1
#define GET_INPUT 2

vector<int> sample;
vector<int> mem;
vector<int> in;
vector<int> mp;

vector<int> parse_int_list(string s){
    stringstream ss(s);
    int x;
    vector<int> ret;
    while(ss >> x){
        ret.push_back(x);
    }
    return ret;
}

int dp(int index){
    if(mem[index] != 0) return mem[index];
    for(int i = 0; i < index; i++){
        if(mp[i] < mp[index]){
            mem[index] = max(mem[index],dp(i)+1);
        }
    }
    if(mem[index] == 0) mem[index] = 1;
    return mem[index];
}

int main(){
    string s;
    int state = GET_TEST;
    int test;
    while(getline(cin,s)){
        in = parse_int_list(s);
        if(in.size() == 1){
            test = in[0];
            state = GET_SAMPLE;
            continue;
        }
        if(state == GET_SAMPLE){
            sample = in;
            state = GET_INPUT;
            mp.clear();
            mp.resize(sample.size()+1);
            for(int i = 0; i < sample.size(); i++){
                mp[sample[i]] = i;
            }
            continue;
        }
        if(state == GET_INPUT){
            mem.clear();
            mem.resize(in.size());
            mem[0] = 1;
            int ans = 0;
            for(int i = 0; i < sample.size(); i++){
                mp[sample[i]-1] = in[i];
            }
            for(int i = 0; i < in.size(); i++){
                //cout << dp(i) << ' ';
                ans = max(ans,dp(i));
            }
            //cout << endl;
            cout << ans << endl;
        }
    }
    return 0;
}

