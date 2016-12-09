#include<iostream>

using namespace std;

void fill(int* c, int period, int offset, int size, int val){
    int t = offset;
    while(t < size){
        if(!c[t])c[t] = val;
        t += period;
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int days;
        cin >> days;
        int* c = new int[days]{};
        fill(c,7,5,days,2);
        fill(c,7,6,days,2);
        int parties;
        cin >> parties;
        while(parties--){
            int h;
            cin >> h;
            fill(c,h,h-1,days,1);
        }
        int total = 0;
        for(int i = 0; i < days;i++){
            if(c[i] == 1) total++;
        }
        cout << total << endl;
    }
    return 0;
}
