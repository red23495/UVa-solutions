#include<iostream>
#include<cmath>
using namespace std;

void odd(int cr,int cc,long long c,int& ir,int& ic, int root){
    if(c <= root*(root-1)){
        ir = cr - (root/2);
        ic = cc - (root/2);
        ic += (c - (root-1)*(root-1) - 1);
    }
    else{
        ir = cr - (root/2);
        ic = cc + (root/2);
        ir += (c - (root*(root-1) + 1));
    }
}

void even(int cr,int cc,long long c,int& ir,int& ic,int root){
    if(c <= root*(root-1)){
        ir = cr + (root/2);
        ic = cc + (root/2) - 1;
        ic -= (c - (root-1)*(root-1) - 1);
    }
    else{
        ir = cr + (root/2);
        ic = cc - (root/2);
        ir -= (c - (root*(root-1) + 1));
    }
}

int main(){
    int s;
    long long c;
    while(cin >> s >> c && s && c){
        int root = ceil(sqrt(c));
        int cr = ceil(s/2.0);
        int cc = ceil(s/2.0);
        int ir,ic;
        if(root%2) odd(cr,cc,c,ir,ic,root);
        else even(cr,cc,c,ir,ic,root);
        cout <<"Line = " << ir <<", column = "<<ic<<".\n";
    }
    return 0;
}
