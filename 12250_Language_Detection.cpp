#include<string>
#include<iostream>
using namespace std;

int main()
{
    int test = 1;
    string str;
    while(cin >> str && str != "#"){
        cout << "Case " << test << ": ";
        if(str == "HELLO") cout << "ENGLISH";
        else if(str == "HOLA") cout << "SPANISH";
        else if(str == "HALLO") cout << "GERMAN";
        else if(str == "BONJOUR") cout << "FRENCH";
        else if(str == "CIAO") cout << "ITALIAN";
        else if(str == "ZDRAVSTVUJTE") cout << "RUSSIAN";
        else cout << "UNKNOWN";
        cout << endl;
        test++;
    }
    return 0;
}
