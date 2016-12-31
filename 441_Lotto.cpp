#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    bool s = false;
    while(cin >> n && n){
        if(s) cout << endl;
        else s = true;
        vector<int> v(n);
        for(auto& x: v){
            cin >> x;
        }
        for(int a = 0; a < n-5; a++){
            for(int b = a+1; b < n-4; b++){
                for(int c = b+1; c < n-3; c++){
                    for(int d = c+1; d< n-2; d++){
                        for(int e = d+1; e < n-1; e++){
                            for(int f= e+1; f < n; f++){
                                cout << v[a] << ' ' << v[b] << ' ' <<v[c] << ' ' << v[d] << ' ' << v[e] << ' ' << v[f] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
