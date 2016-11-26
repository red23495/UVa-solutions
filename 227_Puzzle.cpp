#include<iostream>
#include<string>
#include<array>
using namespace std;

void swap(char &a, char &b){
    char t = a;
    a = b;
    b = t;
}

int main(){
    int test = 0;
    while(true){
        array<string,5> table;
        for(int i = 0; i < 5; i++){
            getline(cin,table[i],'\n');
            if(table[i][0] == 'Z') return 0;
        }
        if(test) cout << endl;
        test++;
        int x,y;
        for(int i = 0; i < 5; i++){
            bool check = false;
            for(int j = 0; j < 5; j++){
                if(table[j][i] == ' '){
                    x = i;
                    y = j;
                    check = true;
                    break;
                }
            }
            if(check) break;
        }
        char c;
        bool result = true;
        while(cin.get(c) && c != '0'){
            if(c != 10 && result){
                switch(c){
                case 'A':
                    if(y < 5 && y > 0){
                        swap(table[y][x],table[y-1][x]);
                        y--;
                    }
                    else result = false;
                    break;
                case 'B':
                    if(y < 4 && y >= 0){
                        swap(table[y][x],table[y+1][x]);
                        y++;
                    }
                    else result = false;
                    break;
                case 'L':
                    if(x < 5 && x > 0){
                        swap(table[y][x],table[y][x-1]);
                        x--;
                    }
                    else result = false;
                    break;
                case 'R':
                    if(x < 4 && x >= 0){
                        swap(table[y][x],table[y][x+1]);
                        x++;
                    }
                    else result = false;
                    break;
                default:
                    result = false;
                    break;
                }
            }
        }
        if(cin.peek() == 10) cin.ignore();
        cout << "Puzzle #" << test << ":\n";
        if(result){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    cout << table[i][j];
                    if(j != 4) cout << ' ';
                }
                cout << endl;
            }
        }
        else{
            cout << "This puzzle has no final configuration.\n";
        }
    }
    return 0;
}
