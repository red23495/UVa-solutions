#include<iostream>
#include<vector>

using namespace std;

bool check(vector<vector<int>> &v, int r, int c, int key){
    if(c-1 >= 0 && v[c-1][r] == key) return true;
    if(c+1 < v.size() && v[c+1][r] == key) return true;
    if(r-1 >= 0 && v[c][r-1] == key) return true;
    if(r+1 < v[c].size() && v[c][r+1] == key) return true;
    return false;
}

void spread(vector<vector<int>> &v, int r, int c, int key){
    v[c][r] = -1;
    if(c-1 >= 0 && v[c-1][r] == key) spread(v,r,c-1,key);
    if(c+1 < v.size() && v[c+1][r] == key) spread(v,r,c+1,key);
    if(r-1 >= 0 && v[c][r-1] == key) spread(v,r-1,c,key);
    if(r+1 < v[c].size() && v[c][r+1] == key) spread(v,r+1,c,key);
}

int main()
{
    int test = 0;
    int r,c;
    while(cin >> r >> c && r && c){
        if(test++) cout << endl;
        vector<vector<int>> table(c,vector<int>(r));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> table[j][i];
            }
        }
        int nr, nc;
        while(cin >> nr >> nc && nc && nr){
            --nr;--nc;
            if(nc < table.size() && nr < table[nc].size()){
                if(check(table,nr,nc,table[nc][nr])){
                    spread(table,nr,nc,table[nc][nr]);
                    for(int i = table.size()-1; i >= 0; i--){
                        for(int j = table[i].size()-1; j >= 0;j--){
                            if(table[i][j] == -1) table[i].erase(table[i].begin()+j);
                        }
                        if(table[i].size() == 0) table.erase(table.begin()+i);
                    }
                }
            }
        }
        cout << "Grid " << test << ".\n";
        if(!table.size()) cout << "    Game Won\n";
        else{
            for(int i = r-1; i >= 0; i--){
                cout << "    ";
                for(int j = 0; j < c; j++){
                    if(i < table[j].size() && j < table.size())
                        cout << table[j][i];
                    else cout <<' ';
                    if(j == c-1) cout << endl;
                    else cout << ' ';
                }
            }
        }
    }
    return 0;
}
