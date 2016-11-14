#include<iostream>
#include<string>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        int won;
        cin >> won;
        int oulders = 0;
        double point = 0;
        for(int j = 0; j < won; j++){
            string s1,of,s2;
            cin >> s1;
            if(s1 == "fool"){
                oulders++;
                point += 4.5;
                continue;
            }
            cin >> of >> s2;
            if(s1 == "king") point+=4.5;
            else if(s1 == "queen") point += 3.5;
            else if (s1 == "knight") point += 2.5;
            else if (s1 == "jack") point += 1.5;
            else if(s1 == "one" || s1 == "twenty-one"){
                point += 4.5;
                oulders++;
            }
            else point+=0.5;
        }
        int required;
        switch(oulders){
        case 3:
            required = 36;
            break;
        case 2:
            required = 41;
            break;
        case 1:
            required = 51;
            break;
        case 0:
            required = 56;
            break;
        }
        cout << "Hand #" << i << endl;
        if(required > point)
            cout << "Game lost by " << required - int(point) << " point(s).\n";
        else
            cout << "Game won by " << int(point) -  required << " point(s).\n";
        if(i != test)cout << endl;
    }
    return 0;
}
