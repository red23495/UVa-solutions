#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        queue<char> end;
        stack<queue<char>> home;
        bool l = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '['){
                i++;
                queue<char> t;
                while((s[i] != '[' && s[i] != ']') && i < s.length()){
                    t.push(s[i]);
                    i++;
                }
                home.push(t);
                i--;
            }
            else if(s[i] != ']') end.push(s[i]);
        }
        while(!home.empty()){
            auto x = home.top();
            home.pop();
            while(!x.empty()){
                auto y = x.front();
                x.pop();
                cout << y;
            }
        }
        while(!end.empty()){
            cout << end.front();
            end.pop();
        }
        cout << endl;
    }
    return 0;
}
