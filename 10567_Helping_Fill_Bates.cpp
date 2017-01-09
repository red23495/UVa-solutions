#include<iostream>
#include<vector>
#include<string>

using namespace std;

int nxt[52];
int states [1000001][52];
int to_index(char c){
    if(c < 'a') return c-'A';
    return c-'a'+26;
}
int main(){
    string s;
    cin >> s;
    for(int i = s.length() -1; i >= 0; i--){
        for(int j = 0; j < 52; j++){
            states[i+1][j] = nxt[j];
        }
        nxt[to_index(s[i])] = i+1;
    }
    for(int i = 0; i < 52; i++) states[0][i] = nxt[i];
    //for(int i = 0; i < s.length(); i++) {for(int j = 0; j < 52; j++) cout << states[i][j] << ' '; cout << endl;}
    int q;
    cin >> q;
    while(q--){
        cin >> s;
        int last = 0;
        for(int i = 0; i < s.length();i++){
            //cout << last << ' ';
            last = states[last][to_index(s[i])];
            if(!last) break;
        }
        //cout << endl;
        if(last) cout << "Matched " << states[0][to_index(s[0])]-1 << ' ' << last-1 << endl;
        else cout << "Not matched\n";
    }
}
