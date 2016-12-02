#include<iostream>
#include<string>
#include<unordered_map>
#include<iomanip>
using namespace std;

unordered_map<char,char> weak = {{'r','s'},{'s','p'},{'p','r'}};

int Win(char m1,char m2){
    if(weak[m1] == m2) return 1;
    else return 2;
}

int main()
{
    bool first = false;
    int n,k;
    while(cin >> n && n){
        cin >> k;
        if(first) cout << endl;
        else first = true;
        int* turn = new int[n+1]{};
        int* win = new int[n+1]{};
        int limit = k * n * (n-1) / 2;
        for(int i = 0; i < limit; i++){
            int p1,p2;
            string m1,m2;
            cin >> p1 >> m1 >> p2 >> m2;
            if(m1[0] == m2[0]) continue;
            else{
                int r = Win(m1[0],m2[0]);
                if(r == 1) win[p1]++;
                else win[p2]++;
                turn[p1]++;turn[p2]++;
            }
        }
        for(int i = 1; i <= n; i++){
            if(turn[i] == 0) cout << '-' << endl;
            else cout << fixed <<setprecision(3) <<double(win[i])/double(turn[i]) << endl;
        }
        delete[] turn;
        delete[] win;
    }
    return 0;
}
