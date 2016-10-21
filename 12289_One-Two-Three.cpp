#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string num;
        cin >> num;
        if(num.size() == 5) cout << '3';
        else if(num[0] == 'o'){
            if(num[1] == 'w'){
                    if(num[2] == 'o') cout << '2';
                    else cout << '1';
            }
            else cout << '1';
        }
        else if(num[0] == 't'){
            if(num[1] == 'n'){
                    if(num[2] == 'e') cout << '1';
                    else cout << '2';
            }
            else cout << '2';
        }
        else{
            if(num[1] == 'n') cout << '1';
            else cout << '2';
        }
        cout << endl;
    }
    return 0;
}
