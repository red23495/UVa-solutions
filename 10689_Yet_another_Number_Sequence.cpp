#include<bits/stdc++.h>

using namespace std;

int memo[15001];

int main(){
	int test;
	cin >> test;
	while (test--) {
		int m, n;
		cin >> memo[0] >> memo[1] >> n >> m;
		for (int i = 2; i <= 15000; i++) {
			memo[i] = (memo[i - 1] + memo[i - 2]) % 10000;
		}
		if (m == 1) {
			n %= 60;
			n = memo[n] % 10;
		}
		else if (m == 2) {
			n %= 300;
			n = memo[n] % 100;
		}
		else if (m == 3) {
			n %= 1500;
			n = memo[n] % 1000;
		}
		else if (m == 4) {
			n %= 15000;
			n = memo[n];
		}
		cout << n << endl;
	}
	return 0;
}
