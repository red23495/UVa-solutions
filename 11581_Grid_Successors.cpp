#include<iostream>

using namespace std;

bool check(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j]) return false;
        }
    }
    return true;
}

int new_grid(int arr[3][3],int row, int column){
    int n{0};
    if(row > 0) n += arr[row-1][column];
    if(row < 2) n += arr[row+1][column];
    if(column > 0) n += arr[row][column-1];
    if(column < 2) n += arr[row][column+1];
    return n%2;
}

int transform(int arr[3][3]){
    if(check(arr)) return -1;
    int narr[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            narr[i][j] = new_grid(arr,i,j);
        }
    }
    return transform(narr)+1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int arr[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                char c;
                cin >> c;
                arr[i][j] = c - '0';
            }
        }
        cout << transform(arr) << endl;
    }
    return 0;
}
