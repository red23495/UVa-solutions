#include<iostream>

using namespace std;

bool win(char (&table)[3][3],char s){
    for(int i = 0; i < 3; i++){
        if(table[i][0] == s && table[i][1] == s && table[i][2] == s)
            return true;
        if(table[0][i] == s && table[1][i] == s && table[2][i] == s)
            return true;
    }
    if(table[0][0] == s && table[1][1] ==  s && table[2][2] == s) return true;
    if(table[0][2] == s && table[1][1] ==  s && table[2][0] == s) return true;
    return false;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int x = 0, o = 0;
        int i = 0;
        char table[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                char c;
                cin >> c;
                if(c == 'X') x++;
                else if(c == 'O') o++;
                table[i][j] = c;
            }
        }
        if(x == o || x - o == 1){
            if(win(table,'X') && win(table,'O'))
                cout << "no\n";
            else if(win(table,'O') && x != o){
                cout << "no\n";
            }
            else if(win(table,'X') && x == o)
                cout << "no\n";
            else cout << "yes\n";
        }
        else cout << "no\n";
    }
    return 0;
}
