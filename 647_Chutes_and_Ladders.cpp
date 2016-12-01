#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> throws;
    int p;
    while(cin >> p && p) throws.push_back(p);
    while(cin >> p && p){
        int table[101] = {};
        int r1,r2;
        while(cin >> r1 >> r2 && r1 && r2 ){
            table[r1] = r2;
        }
        while(cin >> r1 && r1){
            if(r1 < 0)
                table[-1*r1] = -1;
            else
                table[r1] = -2;
        }
        vector<int> state(p,0);
        vector<bool> miss(p,false);
        int turn = 0;
        int die = 0;
        while(true){
            if(miss[turn]){
                miss[turn] = false;
                turn = (++turn)%state.size();
                continue;
            }
            if(state[turn] + throws[die] < 101){
                state[turn]+=throws[die];
                if(table[state[turn]] == -1){
                    miss[turn] = true;
                }
                else if(table[state[turn]] == -2){
                    die = (++die)%throws.size();
                    continue;
                }
                else if(table[state[turn]]){
                    state[turn] = table[state[turn]];
                }
            }
            if(state[turn] == 100) {
                cout << turn+1 << endl;
                break;
            }
            turn = (++turn)%state.size();
            die = (++die)%throws.size();
        }
    }
    return 0;
}
