#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int test;
    cin >> test;
    cin.ignore();
    for(int i = 1; i <= test; i++){
        char c;
        int arr[100];
        for(int i = 0; i < 100; i++) arr[i] = 0;
        int pointer = 0;
        while(cin.get(c) && c != '\n'){
            if(c == '>') pointer = (pointer != 99)? (pointer+1):0;
            else if(c == '<') pointer = (pointer != 0)? (pointer-1):99;
            else if(c == '+') arr[pointer] = (arr[pointer] != 255)? arr[pointer]+1:0;
            else if(c == '-') arr[pointer] = (arr[pointer] != 0)? arr[pointer]-1:255;
        }
        cout << dec << "Case "<< i << ":";
        for(int i = 0; i < 100; i++)
            cout << ' ' <<hex << uppercase << setw(2) << setfill('0') <<int(arr[i]);
        cout << endl;
    }
    return 0;
}
