#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
using namespace std;

vector<vector<char>> v;
string q,ans;
int r,c;

void setmap(){
    int a = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            //cout << q[a] << endl;
            v[i][j] = q[a++];
        }
    }
}

void write(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            ans.push_back(v[i][j]);
    }
}

void compose(int br,int er,int bc,int ec){
    //cout << br << ' ' << er << ' ' << bc << ' ' << ec << endl;
    if(br > er || bc > ec) return;
    if(br == er && bc == ec) {
        //cout <<br << ' '<< bc << ' ' <<v[br][bc] << endl;
        ans.push_back(v[br][bc]);
        return;
    }
    char ch = v[br][bc];
    bool check = true;
    for(int i = br; i <= er && check; i++){
        for(int j = bc; j <= ec && check; j++){
            if(ch != v[i][j]) check = false;
        }
    }
    //cout << check << endl;
    if(!check){
        ans.push_back('D');
        int midr = (br+er)/2,midc = (bc+ec)/2;
        compose(br,midr,bc,midc);
        compose(br,midr,midc+1,ec);
        compose(midr+1,er,bc,midc);
        compose(midr+1,er,midc+1,ec);
    }
    else ans.push_back(ch);
}

void decompose(int br,int er,int bc,int ec,int &index){
    //cout << br << ' ' << er << ' ' << bc << ' ' << ec << ' ' << q[index]<<endl;
    if(br > er || bc > ec) return;
    if(index >= q.length()) return;
    if(q[index] == 'D'){
        index++;
        int midr = (br+er)/2, midc = (bc+ec)/2;
        decompose(br,midr,bc,midc,index);
        decompose(br,midr,midc+1,ec,index);
        decompose(midr+1,er,bc,midc,index);
        decompose(midr+1,er,midc+1,ec,index);
    }
    else{
        for(int i = br; i <= er; i++){
            for(int j = bc; j <= ec; j++){
                v[i][j] = q[index];
            }
        }
        index++;
    }
    //cout << ans << endl;
}

int main(){
    char ch;
    int nr,nc;
    cin >> ch >> r>> c;
    while(ch != '#'){
        //cout << ch << endl;
        ans.clear();
        q.clear();
        char mode = ch;
        bool run = true;
        while(run){
            while(cin.peek() == '\n') cin.ignore();
            string s;
            getline(cin,s);
            if(s.length() > 1){
                if(s[1] != ' ') q.append(s);
                else{
                    run = false;
                    stringstream ss(s);
                    ss >> ch >> nr >> nc;
                }
            }
            else if(s[0] == '#') {
                ch = '#';
                run = false;
            }else{
                q.append(s);
            }
        }
        //for(int i = 0; i < s.size()-1; i++) if(s[i] != '\n')q.push_back(s[i]);
        v.assign(r,vector<char>(c));
        switch(mode){
        case 'B':
            cout << "D" << setw(4) <<r << setw(4) << c << endl;
            setmap();
            compose(0,r-1,0,c-1);
            break;
        case 'D':
            cout << "B" <<setw(4) <<r << setw(4) << c << endl;
            int i = 0;
            decompose(0,r-1,0,c-1,i);
            write();
            break;
        }
        int index = 0;
        while(index < ans.size()){
            for(int i = 0; i < 50 && index < ans.size(); i++)
                cout << ans[index++];
            cout << endl;
        }
        r = nr; c = nc;
    }
    return 0;
}
