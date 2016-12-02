#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
using namespace std;

bool is_pal(string &str){
    int end = (str.length()-1);
    int half = end/2;
    for(int i = 0; i <= half; i++){
        if(str[i] != str[end-i]) return false;
    }
    return true;
}

int main()
{
    int test;
    int i = 1;
    cin >> test;
    cin.ignore();
    while(test--){
        string str;
        getline(cin,str);
        stringstream ss(str);
        str.clear();
        char c;
        while(ss >> c){
            if(isalpha(c)) str.push_back(tolower(c));
        }
        int r = sqrt(str.length());
        cout << "Case #" << i++ << ":\n";
        if(r*r == str.length() && is_pal(str) ) cout << r << endl;
        else cout << "No magic :(\n";
    }
    return 0;
}
