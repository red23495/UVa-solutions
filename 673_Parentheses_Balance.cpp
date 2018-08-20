#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        stack<char> st;
        bool valid = true;
        for(char c: s){
            if(c == '(' || c == '[') {
                st.push(c);
            }else{
                if(st.empty()){
                    valid = false;
                    break;
                }
                char t = st.top();
                if( (t == '(' && c != ')') || (t == '[' && c != ']') ) {
                    valid = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) valid = false;
        if(valid) cout << "Yes\n"; else cout << "No\n";
    }
}
