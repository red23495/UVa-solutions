#include<bits/stdc++.h>

using namespace std;

class record{
public:
    string val,nrm;
    record(string s){
        val = s;
        nrm = s;
        sort(nrm.begin(),nrm.end());
    }
};

vector<record> v;
vector<string> result;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    string s;
    while(cin >> s && s != "XXXXXX") v.push_back(record(s));
    while(cin >> s && s != "XXXXXX"){
        result.clear();
        sort(s.begin(),s.end());
        for(auto r: v) if(r.nrm == s) result.push_back(r.val);
        sort(result.begin(),result.end());
        for(string res: result){
            cout << res << endl;
        }
        if(!result.size()) cout << "NOT A VALID WORD\n";
        cout << "******\n";
    }
    return 0;
}
