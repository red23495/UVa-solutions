#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<iomanip>
using namespace std;

int main()
{
    string n1,n2;
    while(getline(cin,n1) && getline(cin,n2)){
        stringstream s1(""), s2("");
        for(auto c: n1){
            if(isalpha(c)){
                s1 << int(tolower(c) - 'a' + 1);
            }
        }
        for(auto c: n2){
            if(isalpha(c)){
                s2 << int(tolower(c) - 'a' + 1);
            }
        }
        while(s1.str().size() > 1){
            char x;
            int sum = 0;
            while(s1 >> x)
            {
                sum+= int(x-'0');
            }
            s1.str("");
            s1.clear();
            s1 << sum;
        }
        while(s2.str().size() > 1){
            char x;
            int sum = 0;
            while(s2 >> x)
            {
                sum+=int(x-'0');
            }
            s2.str("");
            s2.clear();
            s2 << sum;
        }
        double r1,r2;
        double rat;
        s1 >> r1; s2 >> r2;
        if(r1 < r2) rat = r1/r2;
        else rat = r2 / r1;
        cout << fixed << setprecision(2)<< rat*100 <<" %" << endl;
    }
    return 0;
}
