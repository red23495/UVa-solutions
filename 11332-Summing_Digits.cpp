#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string str;
    while(cin >> str && str != "0"){
        long long total = 0;
        while(str.size() != 1){
            for(auto c: str){
                total += c-'0';
            }
            stringstream ss("");
            ss << total;
            total = 0;
            str = ss.str();
        }
        cout << str << endl;
    }
    return 0;
}
