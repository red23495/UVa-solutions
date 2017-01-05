#include<iostream>

using namespace std;

int row[8];
void backtrack(int r,int ld, int rd){
    //cout << r << ld << rd << endl;
    if(r == 8) {
        cout << "{";
        for(int i = 0; i < 8; i++){
            if(i) cout << ',';
            cout << row[i];
        }
        cout << "},\n";
        return;
    }
    ld <<= 1; rd >>= 1;
    for(int i = 0; i < 8; i++){
        if(!(row[i] || ((ld & (1 << i)) || (rd & (1 << i))))){
            row[i] = r+1;
            backtrack(r+1,(ld | (1 << i)), (rd | (1 << i)));
            row[i] = 0;
        }
    }
}

int main(){
    cout << "int arr[92][8] = {\n";
    backtrack(0,0,0);
    cout << "}\n";
    return 0;
}
