#include<iostream>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int x = 0; x < test; x++){
        int p, l, r;
        bool finish = false;
        int table[101]={};
        cin >> p >> l >> r;
        int* player = new int[p];
        for(int i = 0; i < p; i++){
            player[i] = 1;
        }
        for(int i = 0; i < l; i++){
            int p,q;
            cin >> p >> q;
            table[p] = q;
        }
        for(int i = 0; i < r; i++){
            int x;
            cin >> x;
            if(!finish){
                player[i%p] += x;
                if(table[player[i%p]]) player[i%p] = table[player[i%p]];
                if(player[i%p] == 100) finish = true;
            }
        }
        for(int i = 0; i < p; i++){
            cout << "Position of player " << i+1 <<" is " << player[i] << ".\n";
        }
        delete[] player;
    }
    return 0;
}
