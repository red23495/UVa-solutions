#include<bits/stdc++.h>

using namespace std;

#define INDEX(A) (A-'A')

vector<string> dictionary;
int letter_count[26];
string s;

void backtrack(int index, int total, string result){
    if(!total) {
        stringstream s1(s),s2(result);
        vector<string> v1,v2;
        string temp;
        while(s1 >> temp) v1.push_back(temp);
        while(s2 >> temp) v2.push_back(temp);
        bool isSame = false;
        for(string a: v1){
            for(string b: v2){
                if(a == b) {
                    isSame = true;
                    break;
                }
            }
            if(isSame) break;
        }
        if(!isSame)cout << s << " = " << result << endl;
        return;
    }
    if(index == dictionary.size()) return;
    int temp_counter[26];
    for(int i = 0; i < 26; i++){
        temp_counter[i] = letter_count[i];
    }
    bool isFit = true;
    for(int i = 0; i < dictionary[index].length() && isFit; i++){
        if(temp_counter[INDEX(dictionary[index][i])]-- <= 0) isFit = false;
    }
    if(isFit){
        for(char c : dictionary[index]){
            letter_count[INDEX(c)]--;
        }
        backtrack(index+1,total-dictionary[index].length(),result+((result == "")?"":" ")+dictionary[index]);
        for(char c : dictionary[index]){
            letter_count[INDEX(c)]++;
        }
    }
    backtrack(index+1,total,result);
}

int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    dictionary.clear();
    while(cin >> s && s[0] != '#'){
        dictionary.push_back(s);
    }
    while(cin.peek() == 10) cin.ignore();
    while(getline(cin,s,'\n') && s[0] != '#'){
        int total{0};
        memset(letter_count,0,sizeof letter_count);
        for(auto c: s) if(c != ' '){letter_count[INDEX(c)]++;total++;}
        backtrack(0,total,string(""));
    }
    return 0;
}
