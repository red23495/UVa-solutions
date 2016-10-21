#include<iostream>
#include<string>

using namespace std;

int main(){
    int test;
    long long money = 0;
    cin >> test;
    for(int i = 0; i < test; i++){
        string com;
        cin >> com;
        if(com[0] == 'd'){
            long long x;
            cin >> x;
            money+=x;
        }
        else{
            cout << money << endl;
        }
    }
    return 0;
}
