#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

int diff(string s){
    bool check[91] = {};
    int count = 0;
    for(auto c: s){
        if(!check[c]){
            check[c] = true;
            count++;
        }
    }
    return count;
}

int main(){
    int test = 0;
    string s;
    while(cin >> s && s != "end"){
        test++;
        int d = diff(s);
        vector<stack<char>> v;
        for(auto c: s){
            int i;
            for(i = 0; i < v.size(); i++){
                if(v[i].top() >= c){
                    v[i].push(c);
                    break;
                }
            }
            if(i == v.size()){
                stack<char> st;
                st.push(c);
                v.push_back(st);
            }
            if(d < v.size()) break;
        }
        cout << "Case "<<test<<": ";
        if(d < v.size()) cout << d << endl;
        else cout << v.size() << endl;
    }
    return 0;
}
