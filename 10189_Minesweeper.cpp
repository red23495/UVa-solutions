#include<iostream>

using namespace std;

void fill(char a[100][100], int x, int y, int row, int column){
    for(int i = x-1; i < x+2; i++){
        for(int j = y - 1; j < y+2; j++){
            if(a[i][j] != '*' && i < row && i >= 0 && j < column && j >= 0){
                a[i][j]++;
            }
        }
    }
}

int main(){
    int row, column, test = 0;
    while(cin >> row >> column && row){
        if(test) cout << endl;
        test++;
        char table[100][100];
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                cin >> table[i][j];
                if(table[i][j] =='.') table[i][j] = 0;
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(table[i][j]=='*') fill(table,i,j,row,column);
            }
        }
    cout << "Field #" << test <<":\n";
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(table[i][j] != '*') cout << int(table[i][j]);
                else cout << table[i][j];
            }
            cout << endl;
        }
    }
}
