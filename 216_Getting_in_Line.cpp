#include<bits/stdc++.h>

using namespace std;

int n,x[10],y[10], test;

double dist(int i, int j){
    return 16.0+sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
    while(cin >> n && n){
        for(int i = 0; i < n; i++) cin >> x[i]>>y[i];
        vector<int> v{0,1,2,3,4,5,6,7,8,9};
        vector<int> ans_comb;
        double  ans = numeric_limits<double>::max();
        do{
            double sum = 0.0;
            for(int i = 1; i < n; i++){
                sum += dist(v[i-1],v[i]);
            }
            if(sum < ans){
                ans = sum;
                ans_comb = v;
            }
        }while(next_permutation(v.begin(),v.begin()+n));
        cout << "**********************************************************\n";
        cout << "Network #"<<++test<<endl;
        for(int i = 0; i < n-1; i++){
            cout << "Cable requirement to connect ("<<fixed<<setprecision(2)<<x[ans_comb[i]]<<","<<y[ans_comb[i]]<<") to ("<<x[ans_comb[i+1]]<<","<<y[ans_comb[i+1]]<<") is "<<dist(ans_comb[i],ans_comb[i+1])<<" feet.\n";
        }
        cout << "Number of feet of cable required is "<<fixed<<setprecision(2)<<ans<<".\n";
    }
    return 0;
}
