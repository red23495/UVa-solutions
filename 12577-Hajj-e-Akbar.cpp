#include<iostream>
#include<string>

using namespace std;

int main(){
    int test = 1;
    string str;
    while(cin >> str && str != "*"){
        cout << "Case " << test << ": ";
        if(str[0] == 'H') cout << "Hajj-e-Akbar";
        else cout << "Hajj-e-Asghar";
        cout << endl;
        test++;
    }
    return  0;
}
