#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k;
        int r = k ^ (k >> 1);
        cout << r << endl;
    }
    return 0;
}
