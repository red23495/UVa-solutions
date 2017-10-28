#include<bits/stdc++.h>

using namespace std;

int memo[1000001];

int main(){
	for (int i = 2; i <= 1000000; i++) {
		bool is_prime = true;
		for (int j = 2; j <= sqrt(i) && is_prime; j++) {
			if ((i%j) == 0) is_prime = false;
		}
		if (is_prime) {
			memo[i] = 1;
		}
	}
	int n;
	while (cin >> n) {
		string s = to_string(n);
		reverse(s.begin(), s.end());
		int m = atoi(s.c_str());
		if (!memo[n]) {
			cout << n << " is not prime.\n";
		}
		else if (memo[n] && memo[m] && n != m) {
			cout << n << " is emirp.\n";
		}
		else {
			cout << n << " is prime.\n";
		}
	}
	return 0;
}
