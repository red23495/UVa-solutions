#include<iostream>
#include<vector>
using namespace std;

int abs(int a){return (a < 0)?-a:a;}
int Max = (1 << 31)-1;
int main(){
    int n,test = 0;
    while(cin >> n && n){
        cout << "Case "<<++test<<":\n";
        vector<int> v(n);
        for(auto& x: v) cin >> x;
        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            int dif = Max, sum;
            for(int i = 0; i < v.size(); i++){
                for(int j = i+1; j < v.size(); j++){
                    int a = abs(x-v[i]-v[j]);
                    if(a < dif){
                        dif = a;
                        sum = v[i]+v[j];
                    }
                }
            }
            cout << "Closest sum to "<<x<<" is "<<sum<<".\n";
        }
    }
    return 0;
}
