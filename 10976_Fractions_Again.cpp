#include<iostream>
#include<vector>
using namespace std;

struct record{
    int x;
    int y;
};

int main(){
    int k;
    while(cin >> k){
        vector<record> v;
        for(int x = k+1; x <= k*2; x++){
            int y = (x*k)/(x-k);
            if((k*(x+y)) == (x*y)) v.push_back(record{x,y});
        }
        cout << v.size() << endl;
        for(auto a: v){
            cout << "1/"<<k<<" = 1/"<<a.y<<" + 1/"<<a.x<<endl;
        }
    }
    return 0;
}
