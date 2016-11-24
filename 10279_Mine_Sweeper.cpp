#include<iostream>

using namespace std;

int main(){
    int test{};
    cin >> test;
    for(int x = 1; x <= test; x++){
        if(x != 1) cout << endl;
        int dim{};
        char table[10][10] = {};
        bool mine = false;
        cin >> dim;
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                cin >> table[i][j];
            }
        }
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                char p;
                cin >> p;
                if(p == 'x'){
                    int bomb = 0;
                    if(!mine && table[i][j] == '*') mine = true;
                    for(int p = i-1; p < i+2; p++){
                        for(int q = j-1; q < j+2; q++){
                            if(p < dim && q < dim && p >= 0 && q >= 0 && table[p][q] == '*')
                                bomb++;
                        }
                    }
                    if(table[i][j] != '*')table[i][j] = char(bomb)+'0';
                }
            }
        }
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                if(table[i][j] == '*'){
                    if(mine) cout << '*';
                    else cout << '.';
                }
                else cout << table[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
