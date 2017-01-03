#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    while(cin >> n >> m){
        vector<double> f(n),r(m);
        while(n--){
            cin >> f[n];
        }
        while(m--){
            cin>> r[m];
        }
        double max =  0;
        vector<double> drag;
        drag.reserve(100);
        for(int i = 0; i < f.size(); i++){
            for(int j = 0; j < r.size(); j++){
                drag.push_back(r[j]/f[i]);
            }
        }
        sort(drag.begin(),drag.end());
        for(int i = 0; i < drag.size()-1; i++){
            double x = drag[i+1]/drag[i];
            if(x > max) max = x;
        }
        cout << fixed <<setprecision(2) << max << endl;
    }
    return 0;
}
