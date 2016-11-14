#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int p1[3],p2[2];
    while(cin >> p1[0] >> p1[1] >> p1[2] >> p2[0] >> p2[1] && p1[0]){
        bool avail[53];
        for(int i = 0; i < 53; i++) avail[i] = false;
        sort(p1,p1+3);
        sort(p2,p2+2);
        for(int i = 0; i < 3; i++) avail[p1[i]] = true;
        for(int i = 0; i < 2; i++) avail[p2[i]] = true;
        int w1{0},w2{0};
        for(int i = 1; i >= 0; i--){
            bool t = true;
            for(int j = 0; j < 3; j++){
                if(p1[j] > p2[i]) {
                    w1++;
                    p1[j] = -1;
                    t = false;
                    break;
                }
            }
            if(t) {
                int p = -1;
                while(p1[++p] == -1);
                p1[p] = -1;
                w2++;
            }
        }
        int target = 0;
        if(w1 > w2) target = -1;
        else if(w1 < w2) while(avail[++target]);
        else {
            int t = -1;
            while(p1[++t] == -1);
            t = p1[t];
            while(avail[++t] && t != 53);
            if(t == 53) target = -1;
            else target = t;
        }
        cout << target << endl;
    }
    return 0;
}
