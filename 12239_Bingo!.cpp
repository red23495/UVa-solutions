#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n, b;
    while(cin >> n >> b && b && n)
    {
        int* balls = new int[b];
        bool* check = new bool[n+1]();
        for(int i = 0 ; i < b; i++){
            cin >> balls[i];
        }
        int count = 0;
        for(int i = 0; i < b; i++){
            for(int j = 0; j < b; j++){
                int x = int(abs(balls[i] - balls[j]));
                if(!check[x]){
                     check[x] = true;
                     count++;
                }
            }
        }
        if(count > n) cout << "Y\n";
        else cout << "N\n";
        delete[] balls;
        delete[] check;
    }
    return 0;
}
