#include<bits/stdc++.h>

using namespace std;

struct record{
public:
    string str;
    string nrm;
    record(string s){
        str = s;
        sort(s.begin(),s.end());
        nrm = s;
    }
};
vector<record> v;

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        string s;
        v.clear();
        while(n--){
            cin >> s;
            v.push_back(record(s));
        }
        while(cin >> s && s != "END"){
            cout << "Anagrams for: " << s << endl;
            string t = s;
            sort(s.begin(),s.end());
            int c = 1;
            for(int i = 0; i < v.size(); i++){
                if(v[i].nrm == s) cout << "  " << c++ << ") " << v[i].str << endl;
            }
            if(c == 1) cout << "No anagrams for: " << t << endl;
        }
        if(test) cout << endl;
    }
    return 0;
}
