#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct record{
    string name;
    int low;
    int high;
};

int main(){
    int test;
    cin >> test;
    while(test--){
        int d,q;
        cin >> d;
        vector<record> v;
        v.reserve(10000);
        while(d--){
            int a,b; string s;
            cin >> s >> a >> b;
            v.push_back(record{s,a,b});
        }
        string name;
        cin >> q;
        while(q--){
            int val;
            cin >> val;
            int count = 0;
            for(auto x:v){
                if(x.low <= val && x.high >= val){
                    count++;
                    name = x.name;
                }
                if(count > 1) break;
            }
            if(count == 1) cout << name << endl;
            else cout << "UNDETERMINED\n";
        }
        if(test) cout << endl;
    }
    return 0;
}
