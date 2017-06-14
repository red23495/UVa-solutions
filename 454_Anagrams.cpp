#include<bits/stdc++.h>

using namespace std;

class record{
public:
    string value;
    string normal_form;
    vector<int> anagrams;
    record(string s){
        value = s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' ')normal_form.push_back(s[i]);
        }
        sort(normal_form.begin(),normal_form.end());
    }
};

vector<record> v;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--){
        v.clear();
        while(cin.peek() == 10) cin.ignore();
        string s;
        while(getline(cin,s) && s.length()){
            v.push_back(record(s));
        }
        auto comp = [](record r1, record r2){
                            if(r1.value < r2.value) return true;
                            return false;
                        };
        sort(v.begin(),v.end(),comp);
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i].normal_form == v[j].normal_form) v[i].anagrams.push_back(j);
            }
        }
        for(auto r: v){
            for(auto str: r.anagrams){
                cout << r.value << " = " << v[str].value << endl;
            }
        }
        if(n) cout << endl;
    }
    return 0;
}
