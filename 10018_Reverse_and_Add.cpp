#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

bool is_pal(string &str){
    int end = str.length()-1;
    int half = end/2;
    for(int i = 0; i <= half; i++){
        if(str[i] != str[end-i]) return false;
    }
    return true;
}

void generate(string &str, int &count){
    string rev = str;
    reverse(rev.begin(),rev.end());
    unsigned long long i1,i2;
    stringstream ss1(str),ss2(rev);
    ss1 >> i1; ss2 >> i2;
    i1+=i2;
    stringstream ss("");
    ss << i1;
    str = ss.str();
    count++;
}

int main()
{
    int test;
    cin >> test;
    while(test--){
        string str;
        cin >> str;
        int count = 0;
        while(!is_pal(str) || !count){
            generate(str,count);
        }
        cout << count << ' ' << str << endl;
    }
    return 0;
}
