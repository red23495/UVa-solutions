#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int test = 0;
    int r,c;
    while(cin >> r >> c && r){
        if(test++) cout << endl;
        char table[10][10] = {};
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                while(cin.peek() == 10) cin.ignore();
                cin.get(table[i][j]);
            }
        }
        int no[10][10] = {};
        int count = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(table[i][j] != '*' && (!i||!j|| table[i-1][j] == '*' || table[i][j-1] == '*')){
                    no[i][j] = ++count;
                }
            }
        }
        cout << "puzzle #"<< test <<":\nAcross\n";
        for(int i = 0; i < r; i++){
            bool check = false;
            for(int j = 0; j < c; j++){
                if(check && table[i][j] == '*') check = false;
                else if(!check && table[i][j] != '*'){
                    if(table[i][j-1] == '*' || !j){
                        check = true;
                        cout << setw(3) << no[i][j] << '.';
                    }
                }
                if(check){
                    cout << table[i][j];
                    if(j == c-1 || table[i][j+1] == '*')
                    {
                        cout << endl;
                        check = false;
                    }
                }
            }
        }
        cout << "Down\n";
        for(int i = 0; i < r; i++){
            bool check = false;
            for(int j = 0; j < c; j++){
                if(check && table[i][j] == '*') check = false;
                else if(!check && table[i][j] != '*'){
                    if(table[i-1][j] == '*' || !i){
                        check = true;
                        cout << setw(3) << no[i][j] << '.';
                    }
                }
                int x = i;
                while(check){
                    cout << table[x][j];
                    if(x == r-1 || table[x+1][j] == '*')
                    {
                        cout << endl;
                        check = false;
                    }
                    x++;
                }
            }
        }
    }
    return 0;
}
