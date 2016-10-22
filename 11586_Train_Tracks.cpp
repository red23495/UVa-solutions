#include<iostream>

using namespace std;

int main(){
    int test;
    cin >> test;
    cin.ignore();
    for(int i = 0; i < test; i++){
        int m{0},f{0};
        char c;
        while(cin.get(c) && c != '\n'){
            if(c == 'M' || c=='F'){
                if(c == 'M'){
                    m++;
                }else if(c == 'F'){
                    f++;
                }
            }
        }
        if(m == f && m != 1 && f != 1) cout << "LOOP";
        else cout << "NO LOOP";
        cout << endl;
    }
}
