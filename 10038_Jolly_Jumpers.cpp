#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    while(cin >> t){
        bool* check = new bool[t]{true};
        bool jolly = true;
        int prev ;
        cin >> prev;
        for(int i = 0; i < t-1; i++){
            int c;
            cin >> c;
            if(jolly){
                int diff = abs(c-prev);
                if(!check[diff] && diff < t){
                    check[diff] = true;
                    prev = c;
                }else jolly = false;
            }
        }
        if(jolly) cout << "Jolly\n";
        else cout << "Not jolly\n";

    }
    return 0;
}
