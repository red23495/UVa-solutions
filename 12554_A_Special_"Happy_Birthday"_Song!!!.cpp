#include<iostream>
#include<string>

using namespace std;

string str[16] = {"Happy","birthday","to","you",
                    "Happy","birthday","to","you",
                    "Happy","birthday","to","Rujia",
                    "Happy","birthday","to","you"};

int main()
{
    int n;
    string arr[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0, t = 0; t != 0 || i < n; i++, t++, t %= 16)
        cout << arr[i%n] << ": " << str[i%16] << endl;
    return 0;
}
