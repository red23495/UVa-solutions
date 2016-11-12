#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

enum _rank {HIGH,PAIR,DOUBLE,TRIPLE,STRAIGHT,FLUSH,HOUSE,QUAD,ROYAL};

class hand{
    map<char,int> h;
    char pair1 = '\0';
    char pair2 = '\0';
    char triple = '\0';
    char quad = '\0';
    char flush = '\0';
    char straight = '\0';
    _rank r ;
public:
    hand(vector<string> l){
        char c1,c2,last = '\0';
        int suit = -1;
        for(auto s: l){
            c1 = s[1];
            c2 = s[0];
            if(last != c1){
                last = c1;
                suit++;
            }
            switch(c2){
            case 'T':
                h['9'+1]++;
                break;
            case 'J':
                h['9'+2]++;
                break;
            case 'Q':
                h['9'+3]++;;
                break;
            case 'K':
                h['9'+4]++;
                break;
            case 'A':
                h['9'+5]++;
                break;
            default:
                h[c2]++;
                break;
            }
        }
        if(!suit) flush = (--h.end())->first;
        straight = (--h.end())->first;
        char p = h.begin()->first;
        int count = 0;
        for(auto i = ++h.begin(); i != h.end(); i++,count++ ){
            if(i->first == ++p) continue;
            straight = '\0';
            break;
        }
        if(count < 4) straight = '\0';
        if(!flush && !straight){
            for(auto i = h.begin(); i != h.end(); i++){
                switch(i->second){
                case 2:
                    if(!pair1) pair1 = i->first;
                    else pair2 = i->second;
                    break;
                case 3:
                    triple = i->first;
                    break;
                case 4:
                    quad = i->first;
                    break;
                }
            }
        }
        set_rank();
    }

    int high(hand p2){
        auto i1 = (--h.end());
        auto i2 = (--p2.h.end());
        while(true){
            if(i1->first > i2->first) return 1;
            else if(i1->first < i2->first) return 0;
            else{
                if(i1 == h.begin()) return 2;
                --i1;--i2;
            }
        }
    }
    void set_rank(){
        if(straight && flush) r = ROYAL;
        else if(quad) r = QUAD;
        else if(triple && pair1) r = HOUSE;
        else if(flush) r = FLUSH;
        else if(straight) r = STRAIGHT;
        else if(triple) r = TRIPLE;
        else if(pair1 && pair2) r = DOUBLE;
        else if(pair1) r = PAIR;
        else r = HIGH;
    }
    int win(hand p2){
        if(r > p2.r) return 1;
        else if(r < p2.r) return 0;
        else{
            switch(r){
            case ROYAL:
                if(straight > p2.straight) return 1;
                else if(straight < p2.straight) return 0;
                else return 2;
            case QUAD:
                if(quad > p2.quad) return 1;
                else if(quad < p2.quad) return 0;
                else return 2;
            case HOUSE:
                if(triple > p2.triple) return 1;
                else if(triple < p2.triple) return 0;
                else return 2;
            case FLUSH:
            case STRAIGHT:
                return high(p2);
            case TRIPLE:
                if(triple > p2.triple) return 1;
                else if(triple < p2.triple) return 0;
                else return 2;
            case DOUBLE:
                if(pair2 > p2.pair2) return 1;
                else if(pair2 < p2.pair2) return 0;
                else{
                    if(pair1 > p2.pair1) return 1;
                    else if(pair1 < p2.pair1) return 0;
                    else return high(p2);
                }
            case PAIR:
                if(pair1 > p2.pair1) return 1;
                else if(pair1 < p2.pair1) return 0;
                else return high(p2);
            case HIGH:
                return high(p2);
            }
        }
    }
};

int main()
{
    string str;
    while(getline(cin,str,'\n')){
        stringstream ss(str);
        vector<string> h1(5), h2(5);
        for(int i = 0; i < 5; i++){
            ss >> h1[i];
        }
        for(int i = 0; i < 5; i++){
            ss >> h2[i];
        }
        hand black(h1);
        hand white(h2);
        int result = black.win(white);
        switch(result){
        case 1:
            cout << "Black wins.\n";
            break;
        case 0:
            cout << "White wins.\n";
            break;
        case 2:
            cout << "Tie.\n";
            break;
        }
    }
    return 0;
}
