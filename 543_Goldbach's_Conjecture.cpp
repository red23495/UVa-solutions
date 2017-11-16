#include<bits/stdc++.h>

using namespace std;

int is_prime[1000001];
vector<int> primes;

int main() {
	primes.reserve(80000);
	is_prime[0] = is_prime[1] = 1;
	for(int i = 2; i <= 1000000; ){
		if(is_prime[i] == 0){
			primes.push_back(i);
			for(int j = i*i; i <= 1000 && j <= 1000000; j += i){
				is_prime[j] = 1;
			}
		}
		if (i == 2) i++;
		else i += 2;
	}

	int n;

	while(cin >> n && n ){
		int a = 0 , b = 0;
		int half = n / 2;
		for(int i = 0; !a && i < primes.size() && primes[i] <= half; i++){
			//cout << i << ' ' << primes[i] << ' ' << n - primes[i] << endl;
			if(is_prime[n - primes[i]] == 0){
				a = primes[i]; b = n - primes[i];
			}
		}
		if (a > b) swap(a,b);
		if(a) cout << n << " = " << a << " + " << b << endl;
		else cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
