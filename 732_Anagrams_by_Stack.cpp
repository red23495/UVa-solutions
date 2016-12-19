#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void generate(string org, string ana, int i1, int i2, stack<char> s, string r, vector<string>& v){
    if(i1 == org.length()){
        if(s.empty()) v.push_back(r);
        else if(s.top() == ana[i2]){
            s.pop();
            r.push_back('0');
            generate(org,ana,i1,i2+1,s,r,v);
        }
    }
    else if(!s.empty() && s.top() == ana[i2]){
        auto x = s;
        x.push(org[i1]);
        generate(org,ana,i1+1,i2,x,r+"1",v);
        s.pop();
        r.push_back('0');
        generate(org,ana,i1,i2+1,s,r,v);
    }
    else{
        s.push(org[i1]);
        generate(org,ana,i1+1,i2,s,r+"1",v);
    }
}

int main(){
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        cout << "[\n";
        vector<string> v;
        if(s1.length() == s2.length())
            generate(s1,s2,0,0,stack<char>{},"",v);
        sort(v.begin(),v.end(),[](string x, string y){return (x > y);});
        for(auto s: v){
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '0') cout << 'o';
                else cout << 'i' ;
                if(i < s.length()-1) cout << ' ';
            }
            if(s.length() > 0)cout << endl;
        }
        cout << "]\n";
    }
    return 0;
}
