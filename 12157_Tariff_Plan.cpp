#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 1 ; i <= test; i++){
        int t;
        cin >> t;
        int m = 0;
        int j = 0;
        for(int i = 0; i < t ; i++){
            double x;
            cin >> x;
            m += int(ceil((x+1)/30))*10;
            j += int(ceil((x+1)/60))*15;
        }
        cout << "Case " << i <<": ";
        if(m < j)
            cout << "Mile " << m;
        else if(j < m)
            cout << "Juice " << j;
        else cout << "Mile Juice " << m;
        cout << endl;
    }
    return 0;
}
