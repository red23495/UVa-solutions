#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int position = 0;
        int record[110];
        string str;
        int no;
        cin >> no;
        cin.ignore();
        for(int i = 0; i < no ; i++){
            getline(cin,str,'\n');
            if(str[0] == 'L'){
                record[i] = -1;
                position -=1;
            }else if(str[0] == 'R'){
                record[i] = 1;
                position +=1;
            }else {
                stringstream ss(str);
                string ig;
                int id;
                ss >> ig >> ig >> id;
                record[i] = record[id-1];
                position+= record[id-1];
            }
        }
        cout << position << endl;
    }
    return 0;
}
