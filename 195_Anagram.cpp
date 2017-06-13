#include<bits/stdc++.h>

using namespace std;

vector<string> v;
string s;

class record{
public:
    int index;
    string val;
    record(int i,string s){
        index = i;
        for(char& c: s) c = toupper(c);
        sort(s.begin(),s.end());
        val = s;
    }
};

int total;
vector<record> dict;
vector<string> result;
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    v.clear();
    dict.clear();
    result.clear();
    total = 0;
    while(cin >> s && s != "#"){
        v.push_back(s);
        dict.push_back(record(total++,s));
    }
    sort(dict.begin(),dict.end(),[](record r1, record r2){ return r1.val < r2.val;});
    for(int i = 0; i < dict.size(); i++){
        if(!((i != 0 && dict[i-1].val == dict[i].val)||(i != (dict.size()-1) && dict[i+1].val == dict[i].val)))
            result.push_back(v[dict[i].index]);
    }
    sort(result.begin(),result.end());
    for(string s: result){
        cout << s << endl;
    }
    return 0;
}
