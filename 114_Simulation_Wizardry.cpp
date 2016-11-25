#include<iostream>

using namespace std;

int navigateX[4] = {1,0,-1,0};
int navigateY[4] = {0,1,0,-1};

int main(){
    char table[51][51] = {};
    int cost[51][51];
    int point[51][51];
    int y,x;
    cin >> x >> y;
    for(int i = 0; i <x; i++){
        table[0][i] = 'w'; table[y-1][i] = 'w';
    }
    for(int i = 0; i <y; i++){
        table[i][0] = 'w'; table[i][x-1] = 'w';
    }
    int wallCost, bumper;
    cin >> wallCost >> bumper;
    for(int i = 0; i < bumper; i++){
        int tx,ty,v,c;
        cin >> tx >> ty >> v >> c;
        tx--;ty--;
        table[ty][tx] = 'b';
        cost[ty][tx] = c;
        point[ty][tx] = v;
    }
    int bx, by, dir, life, accum = 0;
    while(cin >> bx >> by >> dir >> life){
        bx--;by--;
        int gain = 0;
        while(--life > 0){
            int nx, ny;
            nx = bx+navigateX[dir];
            ny = by+navigateY[dir];
            switch(table[ny][nx]){
            case 'w':
                life -= wallCost;
                dir = (dir==0)?3:dir-1;
                break;
            case 'b':
                life -= cost[ny][nx];
                gain+= point[ny][nx];
                dir = (dir==0)?3:dir-1;
                break;
            default:
                bx = nx;
                by = ny;
                break;
            }
        }
        cout << gain << endl;
        accum+=gain;
    }
    cout << accum << endl;
    return 0;
}
