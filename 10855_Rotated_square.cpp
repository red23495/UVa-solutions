#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<char>> &v){
    vector<vector<char>>temp(v.size(),vector<char>(v.size()));
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            temp[j][v.size()-i-1] = v[i][j];
        }
    }
    v = temp;
}
bool check(vector<vector<char>> small, vector<vector<char>> large, int r , int c){
    for(int i = r, p = 0; p < small.size(); i++,p++){
        for(int j = c, q = 0; q < small.size(); j++,q++){
            if(small[p][q] != large[i][j]) return false;
        }
    }
    return true;
}
int match(vector<vector<char>> small, vector<vector<char>> large){
    int count = 0;
    for(int i = 0; (i+small.size()-1) < large.size(); i++){
        for(int j = 0; (j+small.size()-1) < large.size(); j++){
            if(check(small,large,i,j)) count++;
        }
    }
    return count;
}



int main(){
    int l,s;
    while(cin >> l >> s && l && s){
        vector<vector<char>> big(l,vector<char>(l)),small(s,vector<char>(s));
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                cin >> big[i][j];
            }
        }
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                cin >> small[i][j];
            }
        }
        cout << match(small,big) << ' ';
        rotate(small);
        cout << match(small,big) << ' ';
        rotate(small);
        cout << match(small,big) << ' ';
        rotate(small);
        cout << match(small,big) << endl;
    }
    return 0;
}
