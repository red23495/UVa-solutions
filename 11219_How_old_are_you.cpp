#include<bits/stdc++.h>

using namespace std;

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);

class Date{
    int day,month,year;
public:
    Date(int d, int m, int y){
        day = d; month = m; year = y;
    }
    int operator -(Date rhs){
        int ret = year - rhs.year;
        if(month < rhs.month) ret--;
        else if(month == rhs.month && day < rhs.day) ret--;
        return ret;
    }
};

int main(){
    int test;
    scanf("%d",&test);
    for(int t = 1; t <= test; t++){
        int d,m,y;
        scanf("%d/%d/%d",&d,&m,&y);
        Date cur(d,m,y);
        scanf("%d/%d/%d",&d,&m,&y);
        Date birth(d,m,y);
        int age = cur - birth;
        printf("Case #%d: ",t);
        if(age < 0) printf("Invalid birth date\n");
        else if(age > 130) printf("Check birth date\n");
        else printf("%d\n",age);
    }
    return 0;
}

