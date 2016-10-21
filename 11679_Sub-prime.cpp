#include<iostream>
using namespace std;

int main(){

    int bank , debt;
    while(cin >> bank >> debt && bank && debt){
        int money[20];
        for(int i = 0; i < bank; i++){
            cin >> money[i];
        }
        for(int i = 0; i < debt ; i++){
            int from,to,val;
            cin >> from >> to >> val;
            money[from-1] -= val;
            money[to - 1] += val;
        }
        bool check = true;
        for(int i = 0; i < bank && check; i++)
            if(money[i] < 0) check = false;
        if(check) cout << 'S';
        else cout << 'N';
        cout << endl;
    }
    return 0;
}
