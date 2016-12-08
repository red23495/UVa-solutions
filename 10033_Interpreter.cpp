#include<iostream>
#include<string>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while(test--){
        string s;
        int reg[10] = {};
        int ram[1000] = {};
        while(cin.peek() == 10) cin.ignore();
        int ite = 0;
        while(getline(cin,s,'\n') && s != ""){
            ram[ite++] = (s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
        }
        ite = 0;int count = 0, x;
        while(++count && (x = ram[ite++]) != 100){
            int x1 = x/100, x2 = (x/10)%10, x3 = (x%100)%10;
            switch(x1){
            case 2:
                reg[x2] = x3;
                break;
            case 3:
                reg[x2] += (x3);
                reg[x2]%=1000;
                break;
            case 4:
                reg[x2] *= (x3);
                reg[x2]%=1000;
                break;
            case 5:
                reg[x2] = reg[x3];
                break;
            case 6:
                reg[x2] += reg[x3];
                reg[x2]%=1000;
                break;
            case 7:
                reg[x2] *= reg[x3];
                reg[x2]%=1000;
                break;
            case 8:
                reg[x2] = ram[reg[x3]];
                reg[x2]%=1000;
                break;
            case 9:
                ram[reg[x3]] = reg[x2];
                ram[reg[x3]]%=1000;
                break;
            case 0:
                if(reg[x3]) ite = reg[x2];
                break;
            }
        }
        cout << count << endl;
        if(test) cout << endl;
    }
    return 0;
}
