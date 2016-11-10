#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

bool isface(char c){
    if (c == 'A' || c == 'J' || c == 'Q' || c == 'K')
        return true;
    return false;
}
int point(vector<char> &r, int total ,bool &check){
    int ret = 0;
    for(auto c: r){
        switch(c){
        case 'A':
            ret+=4;
            check = true;
            break;
        case 'K':
            ret+=3;
            if(total > 1) check = true;
            else ret-=1;
            break;
        case 'Q':
            ret+=2;
            if(total > 2) check = true;
            else ret -= 1;
            break;
        case 'J':
            if(total > 3) ret += 1;
            break;
        }
    }
    return ret;
}
void point2(int &p, int t){
    if( t == 2) p++;
    else if(t < 2) p+=2;
}
int main()
{
    string s;
    while(getline(cin,s,'\n')){
        stringstream ss(s);
        vector<char> s,h,d,c;
        int t_s = 0, t_h = 0, t_d = 0, t_c = 0;
        char rank,suit;
        while(ss >> rank >> suit){
            switch(suit){
            case 'S':
                t_s++;
                if(isface(rank)) s.push_back(rank);
                break;
            case 'H':
                t_h++;
                if(isface(rank)) h.push_back(rank);
                break;
            case 'D':
                t_d++;
                if(isface(rank)) d.push_back(rank);
                break;
            case 'C':
                t_c++;
                if(isface(rank)) c.push_back(rank);
                break;
            }
        }
        bool s_close = false, h_close = false, d_close = false, c_close = false;
        int trump = point(s,t_s,s_close)+point(h,t_h,h_close)+point(d,t_d,d_close)+point(c,t_c,c_close);
        bool no_trump = false;
        if( trump > 15 && s_close && h_close && d_close && c_close) no_trump = true;
        if(no_trump) cout << "BID NO-TRUMP\n";
        else{
            point2(trump,t_s);point2(trump,t_h);point2(trump,t_d);point2(trump,t_c);
            if(trump < 14) cout << "PASS\n";
            else{
                char max1,max2;
                int m1,m2;
                if(t_s < t_h) {max1 = 'H'; m1 = t_h;} else {max1 = 'S'; m1 = t_s;}
                if(t_d < t_c) {max2 = 'C'; m2 = t_c;} else {max2 = 'D'; m2 = t_d;}
                if(m1 < m2) max1 = max2;
                cout << "BID " << max1 << '\n';
            }
        }
    }
    return 0;
}
