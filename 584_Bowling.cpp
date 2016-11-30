#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str,'\n') && str[0] != 'G'){
        vector<char> s;
        for(auto c: str){
            if(c != ' ') s.push_back(c);
        }

        int turn = 0;
        int index = 0;
        int total = 0;
        while(turn < 10){
            if(s[index] == 'X'){
                total += 10;
                if(s[index+1] == 'X') {
                    total+=10;
                    if(s[index+2] == 'X') total+=10;
                    else total+= s[index+2]-'0';
                }
                else if(s[index+2] == '/') total+= 10;
                else total = total + (s[index+1]-'0') + (s[index+2]-'0');
                index += 1;
            }
            else if(s[index+1] == '/'){
                total+=10;
                if(s[index+2] == 'X') total+=10;
                else total = total + (s[index+2]-'0');
                index += 2;
            }
            else {
                total = total + (s[index]-'0') + (s[index+1]-'0');
                index += 2;
            }
            turn++;
        }
        cout << total << endl;
    }
    return 0;
}
