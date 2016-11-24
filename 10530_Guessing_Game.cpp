#include<iostream>
#include<string>

using namespace std;

int main()
{
    int c;
    int up = 10, down = 1;
    bool cheat = false;
    while(cin >> c && c){
        string s1,s2;
        cin >> s1 >> s2;
        if(!cheat && s2[0] == 'h'){
            if(c <= down) cheat = true;
            else if(up >= c) up = c-1;
        }
        else if(!cheat && s2[0] == 'l'){
            if(c >= up) cheat = true;
            else if(down <= c) down = c+1;
        }
        else if(s2[0] == 'o'){
            if(c > up || c < down) cheat = true;
            if(cheat) cout <<"Stan is dishonest\n";
            else cout << "Stan may be honest\n";
            up = 10; down = 1; cheat = false;
        }
    }
    return 0;
}
