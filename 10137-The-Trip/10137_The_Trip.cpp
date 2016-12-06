#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    while(cin >> t && t){
        double s[1000];
        double total = 0.0;
        for(int i = 0; i < t; i++){
            cin >> s[i];
            total += s[i];
        }
        double av = total/t;
        double lchange = 0.0, hchange = .0;
        for(int i = 0; i < t; i++){
            if(s[i] < av) lchange += int((av-s[i])*100)/100.0;
            else hchange += int((s[i]-av)*100)/100.0;
        }
        cout << '$' << fixed << setprecision(2) <<((lchange>hchange)?lchange:hchange)<< endl;
    }
    return 0;
}
