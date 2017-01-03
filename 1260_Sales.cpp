#include<iostream>
#include<vector>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            int count = 0;
            for(int j = i-1; j >= 0; j--){
                if(a[j] <= a[i]) count++;
            }
            b[i] = count;
        }
        int sum = 0;
        for(int i = 1; i < n; i++){
            sum+=b[i];
        }
        cout << sum << endl;
    }
    return 0;
}
