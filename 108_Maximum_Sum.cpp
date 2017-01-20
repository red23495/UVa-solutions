#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(i > 0) arr[i][j] += arr[i-1][j];
            if(j > 0) arr[i][j] += arr[i][j-1];
            if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
        }
    }
    int ans = -127*100*100;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < n; l++){
                    int a = arr[k][l];
                    if(i > 0) a -= arr[i-1][l];
                    if(j > 0) a -= arr[k][j-1];
                    if(i > 0 && j > 0) a += arr[i-1][j-1];
                    ans = max(a,ans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
