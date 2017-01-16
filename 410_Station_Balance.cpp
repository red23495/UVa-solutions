#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    int c,n,count = 1;
    while(cin >> c >> n){
        cout << "Set #"<<count++<<endl;
        vector<int> v(2*c);
        double av = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            av += v[i];
        }
        av /= c;
        sort(v.begin(),v.end());
        double im = 0;
        vector<vector<int>> ans(c);
        for(int i = 0; i < c; i++){
            double sum = 0;
            if(v[i]) {
                ans[i].push_back(v[i]);
                sum += v[i];
            }
            if(v[2*c-i-1]) {
                ans[i].push_back(v[2*c-i-1]);
                sum += v[2*c-i-1];
            }
            im += abs(sum -av);
        }
        for(int i = 0; i < c; i++){
            cout << ' ' << i << ':';
            for(int x: ans[i]) cout << ' ' << x;
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << im << endl << endl;
    }
    return 0;
}
