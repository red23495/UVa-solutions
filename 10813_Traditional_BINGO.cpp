#include<iostream>
#include<unordered_map>
using namespace std;

struct rc{
    int r;
    int c;
};

bool win(bool (&b)[5][5]){
    for(int i = 0, j = 0; i < 5 ; i++,j++){
        if(b[i][j]){
            if(i == 4) return true;
        }
        else break;
    }
    for(int i = 4, j = 0; i >= 0 && j < 5 ; i--,j++){
        if(b[i][j]){
            if(i == 0) return true;
        }
        else break;
    }
    for(int i = 0; i < 5; i++){
        if(b[0][i]){
            for(int j = 1; j < 5; j++){
                if(b[j][i]){
                    if(j == 4) return true;
                }
                else break;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        if(b[i][0]){
            for(int j = 1; j < 5; j++){
                if(b[i][j]){
                    if(j == 4) return true;
                }
                else break;
            }
        }
    }
    return false;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        unordered_map<int,rc> cord;
        bool exist[76] = {};
        int card[5][5];
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(i == 2 && j == 2) continue;
                else{
                    cin >> card[i][j];
                    cord[card[i][j]] = rc{i,j};
                    exist[card[i][j]] = true;
                }
            }
        }
        bool bingo = false;
        bool mark[5][5] = {};
        mark[2][2] = true;
        for(int i = 0; i < 75; i++){
            int x;
            cin >> x;
            if(!bingo){
                if(exist[x]){
                    auto c = cord[x];
                    mark[c.r][c.c] = true;
                }
                if(win(mark)){
                    bingo = true;
                    cout << "BINGO after "<<i+1<<" numbers announced\n";
                }
            }
        }
    }
    return 0;
}
