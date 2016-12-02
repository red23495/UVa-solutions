#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

bool ispal(string &s, int start, int end, unordered_map<string,bool> &lib){
    int half = (end - start)/2;
    for(int i = 0; i <= half; i++){
        if(s[start+i] != s[end-i]) return false;
    }
    string sub = s.substr(start,(end-start)+1);
    if(lib[sub]) return false;
    else{
        lib[sub] = true;
        return true;
    }
}

int main()
{
    string str;
    while(getline(cin,str,'\n')){
        int pal = 0;
        unordered_map<string,bool> lib;
        for(int i = 0; i < str.length(); i++){
            for(int j = i; j < str.length();j++){
                if(str[i] == str[j]) if(ispal(str,i,j,lib)) pal++;
            }
        }
        cout << "The string '"<<str<<"' contains "<<pal<<" palindromes.\n";
    }
    return 0;
}
