#define _USE_MATH_DEFINES
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a,int b){ return (a%b == 0)?b:gcd(b,a%b);}

bool naive_prime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void naive_sieve(ll n, vector<ll>& v){
    vector<bool> ch(n+1);
    for(ll i = 2; i <= n; i++){
        if(!ch[i]){
            v.push_back(i);
            for(ll j = (i << 1); j <= n; j += i){
                ch[j] = true;
            }
        }
    }
}

void sieve_pass_0(ll n,vector<ll>& v){
    vector<bool> ch(n>>1);
    v.push_back(2);
    for(ll i = 1; ((i<<1)|1) <= n; i++){
        if(!ch[i]){
            v.push_back((i<<1)|1);
            for(ll j = ((i<<2)|2); j <= n; j += ((i<<1)|1)){
                if(!(j&1)) continue;
                ch[(j>>1)] = true;
            }
        }
    }
}

void sieve_pass_1(ll n,vector<ll>& v){
    vector<bool> ch(n>>1);
    v.push_back(2);
    for(ll i = 1; ((i<<1)|1) <= n; i++){
        if(!ch[i]){
            v.push_back((i<<1)|1);
            for(ll j = ((i<<1)|1)*((i<<1)|1); j <= n; j += ((i<<1)|1)){
                if(!(j&1)) continue;
                ch[(j>>1)] = true;
            }
        }
    }
}

void sieve_pass_2(ll n,vector<ll>& v){
    vector<bool> ch(n>>1);
    v.push_back(2);
    for(ll i = 1; ((i<<1)|1)*((i<<1)|1) <= n; i++){
        if(!ch[i]){
            v.push_back((i<<1)|1);
            for(ll j = ((i<<1)|1)*((i<<1)|1); j <= n; j += ((i<<1)|1)){
                if(!(j&1)) continue;
                ch[(j>>1)] = true;
            }
        }
    }
    ll start = sqrt(n)+1;
    start |= 1;
    while(start <= n){
        if(!ch[start>>1]) v.push_back(start);
        start += 2;
    }
}

void seg_sieve(ll n, vector<ll>& v){
    ll lim = sqrt(n);
    sieve_pass_2(lim,v);
    ll found = v.size();
    ll b = lim+1, e = lim << 1;
    while(b <= n){
        if(e > n) e = n;
        bool mark[lim+1];
        memset(mark,false,sizeof mark);
        for(ll i = 0; i < found; i++){
            ll start = (b/v[i])*v[i];
            while(start < b) start += v[i];
            for(ll j = 0; start+(j*v[i]) <= e; j++) {
                mark[start+(j*v[i])-b]=true;
            }
        }
        for(ll i = 0; i <= e-b; i++){
            if(!mark[i]){
                v.push_back(b+i);
            }
        }
        b = e+1;
        e = b+lim-1;
    }
}


constexpr ll N = 5e7;

//#define NAIVE_PRIME
//#define NAIVE_SIEVE
//#define SIEVE_P0
//#define SIEVE_P1
//#define SIEVE_P2
#define SEG_SIEVE


int main(){
    vector<ll> v1;
    time_t t1,t2;
    ll cnt;
    #ifdef NAIVE_PRIME
    printf("naive prime\n");
    t1 = clock();
    cnt = 0;
    for(ll i = 2; i <= N; i++){
        if(naive_prime(i)){
            cnt++;
            v1.push_back(i);
            //printf("%d found\n",i);
        }
    }
    t2 = clock();
    printf("Prime found %d\n",cnt);
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // NAIVE_PRIME
    #ifdef NAIVE_SIEVE
    printf("naive sieve\n");
    v1.clear();
    t1 = clock();
    naive_sieve(N,v1);
    t2 = clock();
    printf("Prime found %d\n",v1.size());
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // NAIVE_SEIEVE
    #ifdef SIEVE_P0
    printf("Sieve pass 0\n");
    v1.clear();
    t1 = clock();
    sieve_pass_0(N,v1);
    t2 = clock();
    printf("Prime found %d\n",v1.size());
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // SIEVE_P0
    #ifdef SIEVE_P1
    printf("Sieve pass 1\n");
    v1.clear();
    t1 = clock();
    sieve_pass_1(N,v1);
    t2 = clock();
    printf("Prime found %d\n",v1.size());
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // SIEVE_P1
    #ifdef SIEVE_P2
    printf("Sieve pass 2\n");
    v1.clear();
    t1 = clock();
    sieve_pass_2(N,v1);
    t2 = clock();
    printf("Prime found %d\n",v1.size());
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // SIEVE_P2
    #ifdef SEG_SIEVE
    printf("Segmented Sieve\n");
    v1.clear();
    t1 = clock();
    seg_sieve(N,v1);
    t2 = clock();
    printf("Prime found %d\n",v1.size());
    printf("time - %f\n",(t2-t1)/double(CLOCKS_PER_SEC));
    #endif // SEG_SIEVE
    printf("last prime %d\n",v1[v1.size()-1]);
    //for(int i = 0; i < v1.size(); i++) cout << v1[i] << ',';
    return 0;
}
