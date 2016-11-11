#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int t = 0; t < test; t++){
        int tricks ;
        cin >> tricks;
        vector<int>* v = new vector<int>[tricks];
        for(int i = 0; i < tricks; i++){
            for(int j = 0; j < 52; j++){
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        vector<int> seq;
        while(cin.peek() == '\n'){
            int p;
            cin.ignore();
            if(cin.peek() == '\n')
                break;
            else {
                cin >> p;
                if(cin.eof()) break;
                seq.push_back(p);
            }
        }
        int* init =  new int[52];
        for(int i = 0; i < 52; i++) init[i] = i+1;
        for(auto s: seq){
            int* temp = new int[52];
            for(int i = 0; i < 52; i++){
                temp[i] = init[v[s-1][i]-1];
            }
            delete[] init;
            init = temp;
        }
        for(int i = 0; i < 52; i++){
            int check = (init[i]-1)%13;
            switch(check){
            case 12:
                cout << "Ace";
                break;
            case 11:
                cout << "King";
                break;
            case 10:
                cout << "Queen";
                break;
            case 9:
                cout << "Jack";
                break;
            default:
                cout << check+2;
                break;
            }
            cout << " of ";
            switch((init[i]-1)/13){
            case 0:
                cout << "Clubs";
                break;
            case 1:
                cout << "Diamonds";
                break;
            case 2:
                cout << "Hearts";
                break;
            case 3:
                cout << "Spades";
                break;
            }
            cout << endl;
        }
        if(t != test-1)cout << endl;
        delete[] init;
        delete[] v;
    }
}
