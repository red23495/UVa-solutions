#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull memo[80] = { 0,1,2,2 };

ull dp(int x) {
	if (x <= 3) return memo[x];
	if (memo[x]) return memo[x];
	return memo[x] = dp(x - 2) + dp(x - 3);
}

int main() {
	int n;
	while (cin >> n) {
		cout << dp(n) << endl;
	}
	return 0;
}
