#include<iostream>
#include<algorithm>
using namespace std;

int abs(int n){return (n < 0)?-n:n;}

int main(){
    int test;
    cin >> test;
    while(test--){
        int arr[5][5] = {};
        int c;
        cin >> c;
        while(c--){
            int a,b,d;
            cin >> a >> b >> d;
            arr[a][b] = d;
        }
        int r[5] = {};
        int cur = (1 << 31)-1;
        for(int i = 0; i < 25; i++){
            for(int j = i+1; j < 25; j++){
                for(int k = j+1; k < 25; k++){
                    for(int l = k+1; l < 25; l++){
                        for(int m = l+1; m < 25; m++){
                            int sum = 0;
                            for(int x = 0; x < 5; x++){
                                for(int y = 0; y < 5; y++){
                                    int d1 = (abs(x - i/5)+abs(y - i%5))*arr[x][y];
                                    int d2 = (abs(x - j/5)+abs(y - j%5))*arr[x][y];
                                    int d3 = (abs(x - k/5)+abs(y - k%5))*arr[x][y];
                                    int d4 = (abs(x - l/5)+abs(y - l%5))*arr[x][y];
                                    int d5 = (abs(x - m/5)+abs(y - m%5))*arr[x][y];
                                    sum += min(min(d1,d2),min(min(d3,d4),d5));
                                }
                            }
                            if(sum < cur){
                                cur = sum;
                                r[0] = i; r[1] = j; r[2] = k; r[3] = l; r[4] = m;
                            }
                        }
                    }
                }
            }
        }
        cout << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << ' ' << r[4] << endl;
    }
    return 0;
}
