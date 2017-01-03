#include<iostream>

using namespace std;

int p,ansi,ansj,ansn;
int killed[1025][1025];
void kill(int x, int y, int m){
    for(int i = x-p; i <= x+p && i < 1024; i++){
        if(i < 0) continue;
        for(int j = y-p; j <= y+p && j < 1024; j++){
            if(j >= 0)
                killed[i][j]+=m;
        }
    }
}

void find(){
    for(int i = 0; i < 1024; i++){
        for(int j = 0; j < 1024; j++){
            if(killed[i][j] > ansn){
                ansn = killed[i][j];
                ansi = i; ansj = j;
            }
            killed[i][j] = 0;
        }
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int q;
        int x,y,n;
        cin >> p >> q;
        while(q--){
            cin >> x >> y >> n;
            kill(x,y,n);
        }
        ansn = 0;
        find();
        cout << ansi << ' ' << ansj << ' ' << ansn << '\n';
    }
    return 0;
}
