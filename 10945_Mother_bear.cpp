#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
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
    string str;
    while(getline(cin,str) && str != "DONE"){
        stringstream ss(str);
        str.clear();
        char c;
        while(ss >> c){
            if(isalpha(c)){
                str.push_back(tolower(c));
            }
        }
        if(is_pal(str) || str.empty()) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";
    }
    return 0;
}
