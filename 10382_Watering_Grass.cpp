#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

struct range{
    double left;
    double right;
};
vector<range> v;
double n,l,w,_max;
range convert(double p, double r){
    double x = sqrt(abs(pow(r,2)-pow(w/2,2)));
    return range{p-x,p+x};
}
int main(){
    while(cin >> n >> l >> w){
        v.clear();
        for(int i = 0; i < n; i++){
            double a,b;
            cin >> a >> b;
            if(b*2 >= w)v.push_back(convert(a,b));
        }
        auto comp = [](range a, range b){
                        if(a.left < b.left) return true;
                        else if(a.left == b.left){
                            if(a.right > b.right) return true;
                        }
                        return false;
                    };
        sort(v.begin(),v.end(),comp);
        //for(auto x: v) cout << x.left << ' ' << x.right << endl;
        int count = 1;
        int in = -1;
        _max = 0;
        for(int i = 0; i < v.size() && v[i].left <= 0;i++){
            if(v[i].right > _max ) {_max = v[i].right;in = i;}
        }//cout << in << endl;
        if(in == -1) {cout << -1 << endl;continue;}
        //cout << _max << ' ' << l << ' ' << (_max < l) << endl;
        while(_max < l){
            int b = in;
            double next = v[in].right;
            for(int i = in+1; i < v.size() && v[i].left <= _max;i++){
                if(v[i].right > next ) {next = v[i].right;in = i;}
            }
            //cout << in << endl;
            if(in == b){count = -1; break;}
            _max = next;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
