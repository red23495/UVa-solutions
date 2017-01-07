#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
    int d; string c;
    double max = 0, cons = 0, vol = 0;
    int ld = 0, leak = 0;
    while(cin >> d >> c){
        //cout << cons << endl;
        //cout << max << ' ' << vol << endl;
        if(c == "Fuel"){
            string s;
            vol = vol + (d-ld)*(cons+leak);
            cin >> s >> cons;
            if(cons == 0) return 0;
            cons /= 100.0;
            ld = d;
        }
        else if(c == "Leak"){
            vol = vol + (d-ld)*(cons+leak);
            ld = d;
            leak++;
        }
        else if(c == "Gas"){
            string s;
            cin >> s;
            vol = vol + (d-ld)*(cons+leak);
            if(max < vol) max = vol;
            vol = 0;
            ld = d;
        }
        else if(c == "Mechanic"){
            vol = vol + (d-ld)*(cons+leak);
            leak = 0;
            ld = d;
        }
        else {
            //cout << d << ' ' <<ld << endl;
            vol = vol + (d-ld)*(cons+leak);
            if(vol > max) max = vol;
            cout << fixed << setprecision(3) << max << endl;
            max = vol = cons = ld = leak = 0;
        }
    }
    return 0;
}
