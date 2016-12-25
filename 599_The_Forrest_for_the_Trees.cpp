#include<iostream>
#include<string>
#include<bitset>
#include<cctype>
using namespace std;
int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        bitset<26> connect;
        int edge=0;
        while(cin >> s && s[0] != '*'){
            connect[s[1]-'A'] = true; connect[s[3]-'A'] = true;
            edge++;
        }
        int v = 0;
        if(cin.peek() == 10) cin.ignore();
        char c;
        while(cin.get(c) && c != '\n'){
            if(isalpha(c))v++;
        }
        int acorn = v - connect.count();
        int tree = v - edge - acorn;
        cout << "There are "<<tree<<" tree(s) and "<<acorn<<" acorn(s).\n";
    }
    return 0;
}

