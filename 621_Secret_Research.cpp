#include<iostream>
#include<string>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        string s;
        cin >> s;
        if(s == "1" || s == "4" || s == "78")
            cout << '+';
        else if(s[s.size()-1] == '5' && s[s.size() - 2] == '3')
            cout << '-';
        else if(s[0] == '9' && s[s.size() - 1] == '4')
            cout << '*';
        else cout << '?';
        cout << endl;
    }
    return 0;
}
