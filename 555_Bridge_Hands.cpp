#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void lower(char& c2){
    switch(c2){
    case '9'+1:
        c2 = 'T';
        break;
    case '9'+2:
        c2 = 'J';
        break;
    case '9'+3:
        c2 = 'Q';
        break;
    case '9'+4:
        c2 = 'K';
        break;
    case '9'+5:
        c2 = 'A';
        break;
    }
}

int main()
{
    char c;
    while(cin >> c && c != '#'){
        int dealer;
        switch(c){
        case 'N':
            dealer = 0;
            break;
        case 'E':
            dealer = 1;
            break;
        case 'S':
            dealer = 2;
            break;
        case 'W':
            dealer = 3;
            break;
        }
        vector<string> d[4];
        for(int i = 0, j = dealer; i < 52; i++,j++){
            char c1,c2;
            cin >> c1 >> c2 ;
            if(c1 == 'H') c1 = 'Z';
            switch(c2){
            case 'T':
                c2 = '9'+1;
                break;
            case 'J':
                c2 = '9'+2;
                break;
            case 'Q':
                c2 = '9'+3;
                break;
            case 'K':
                c2 = '9'+4;
                break;
            case 'A':
                c2 = '9'+5;
                break;
            }
            char t[3] = {c1,c2,'\0'};
            d[j%4].push_back(t);
        }
        for(int i = 0; i < 4; i++)
            sort(d[i].begin(),d[i].end());
        cout << "S:";
        for(auto c : d[1])
            { if(c[0] == 'Z') c[0] = 'H' ; lower(c[1]);cout <<" "<<c;}
        cout << endl;
        cout << "W:";
        for(auto c : d[2])
            { if(c[0] == 'Z') c[0] = 'H' ;lower(c[1]);cout <<" "<<c;}
        cout << endl;
        cout << "N:";
        for(auto c : d[3])
            { if(c[0] == 'Z') c[0] = 'H' ;lower(c[1]);cout <<" "<<c;}
        cout << endl;
        cout << "E:";
        for(auto c : d[0])
            { if(c[0] == 'Z') c[0] = 'H' ;lower(c[1]);cout <<" "<<c;}
        cout << endl;
    }
    return 0;
}
