#include<iostream>
#include<list>
#include<iomanip>

using namespace std;

int main(){
    while(true){
        list<char> dealer,non_dealer,heap;
        int winner ;
        for(int i = 0; i < 26; i++){
            char c1,c2,c3,c4;
            cin >> c1 ;
            if(c1 == '#') return 0;
            cin >> c2 >> c3 >> c4;
            dealer.push_front(c4);
            non_dealer.push_front(c2);
        }
        bool dealer_turn = false;
        int place = 0;
        bool face = false;
        while(true){
            if(dealer_turn){
                if(!dealer.size()){
                    winner = 2;
                    break;
                }
            }else{
                if(!non_dealer.size()){
                    winner = 1;
                    break;
                }
            }
            char card;
            if(dealer_turn){
                card = dealer.front();
                dealer.pop_front();
            }
            else{
                card = non_dealer.front();
                non_dealer.pop_front();
            }
            heap.push_back(card);
            if (card == 'A' || card == 'K' || card == 'Q' || card == 'J'){
                switch(card){
                case 'A':
                    place = 4;
                    break;
                case 'K':
                    place = 3;
                    break;
                case 'Q':
                    place = 2;
                    break;
                case 'J':
                    place = 1;
                    break;
                }
                face = true;
                dealer_turn = !dealer_turn;
            }
            else{
                if(!face) dealer_turn = !dealer_turn;
                else {
                    --place;
                    if(!place){
                        if(dealer_turn) non_dealer.splice(non_dealer.end(),heap);
                        else dealer.splice(dealer.end(),heap);
                        face = false;
                        dealer_turn = !dealer_turn;
                    }
                }
            }
        }
        cout << winner << setw(3);
        if(winner == 1)
            cout << dealer.size();
        else
            cout << non_dealer.size();
        cout << endl;
    }
    return 0;
}
