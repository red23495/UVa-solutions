#include<bits/stdc++.h>

using namespace std;

void fill(int n, long double* table) {
	table[0] = 0;
	for (int i = 1; i <= n; i++) {
		table[i] = table[i - 1] + log10l(i);
	}
}

int main(){
	int n, k;
	while (cin >> n >> k) {
		long double* memo = new long double[n+1];

		fill(n,memo);
		auto ans = memo[n] - (memo[n - k] + memo[k]);
		cout << int(ans + 1) << endl;

		delete[] memo;
	}
	return 0;
}
