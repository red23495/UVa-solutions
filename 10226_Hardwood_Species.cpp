#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        while(cin.peek() == 10) cin.ignore();
        string s;
        int total = 0;
        map<string,double> m;
        while(getline(cin,s,'\n') && s != ""){
            m[s]++;
            total++;
        }
        for(auto e: m){
            cout << e.first << ' ' << fixed << setprecision(4) << (e.second/total)*100 << endl;
        }
        if(test) cout << endl;
    }
    return 0;
}
