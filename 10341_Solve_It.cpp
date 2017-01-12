#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double p,q,r,s,t,u;

double f(double x){
    return (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u);
}

double fd(double x){
    return (-p*exp(-x)+q*cos(x)-r*sin(x)+s/(cos(x)*cos(x))+2*t*x);
}

int main(){
    while(cin >> p >> q >> r >> s >> t >> u){
        if(f(0)*f(1) > 0) cout << "No solution\n";
        else{
            double last = 0, current = 0.5;
            while(abs(last - current) >= 0.0001){
                    //cout << abs(last - current) << ' ' << f(current) << ' ' << fd(current) << ' ';
                last = current;
                current = (current - (f(current)/fd(current)));
                //cout << current << endl;
            }
            if(!int(current*10000)) current = 0;
            cout << fixed << setprecision(4) << current << endl;
        }
    }
    return 0;
}
