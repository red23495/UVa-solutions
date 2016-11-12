#include<iostream>
#include<string>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        string result;
        for(int i = 0; i < 52; i++){
            string s;
            cin >> s;
            if(i == 32) result = s;
        }
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
