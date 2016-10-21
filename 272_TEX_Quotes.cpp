#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main()
{
    string str ;
    bool end = false;
    getline(cin, str , char(-1));
    stringstream out("");
    for(auto c: str){
        if(c == '\"'){
            if(end)
                out << "''";
            else out << "``";
            end = !end;
        }
        else out << c;
    }
    cout << out.str();
    return 0;
}
