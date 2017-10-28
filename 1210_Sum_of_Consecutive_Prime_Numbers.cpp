#include<bits/stdc++.h>

using namespace std;

int memo[10001];

int main(){
	vector<int> primes;
	for (int i = 2; i <= 10000; i++) {
		bool is_prime = true;
		for (int j = 2; j <= sqrt(i) && is_prime; j++) {
			if ((i%j) == 0) is_prime = false;
		}
		if (is_prime) {
			primes.push_back(i);
		}
	}

	for (int i = 0; i < primes.size(); i++) {
		int n = primes[i];
		int sum = n;
		memo[sum]++;
		for (int j = i + 1; j < primes.size(); j++) {
			int m = primes[j];
			sum += m;
			if (sum > 10000) break;
			memo[sum]++;
		}
	}
	int n;
	while (cin >> n && n) {
		cout << memo[n] << endl;
	}
	return 0;
}
