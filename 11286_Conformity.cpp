#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        map<string,int> m;
        while(n--){
            int a[5];
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
            sort(a,a+5);
            stringstream ss("");
            ss << a[0] << a[1] << a[2] << a[3] << a[4];
            m[ss.str()]++;
        }
        int count = 0, max = 0;
        for(auto e : m){
            if(e.second > max){
                max = e.second;
                count = 1;
            }
            else if(e.second == max){
                count++;
            }
        }
        cout << count*max << endl;
    }
    return 0;
}
