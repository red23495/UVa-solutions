#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n1,n2;
    while(cin >> n1 >> n2 && n1 != -1 && n2 != -1){
        int x1,x2;
        x1 = int(abs(n1-n2));
        x2 = 100 - x1;
        cout << ((x1 < x2)?x1:x2) <<endl;
    }
    return 0;
}
