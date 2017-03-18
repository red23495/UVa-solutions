#include<iostream>
#include<string.h>
using namespace std;

int memo[1000001];

int f(int n) {
	if (memo[n] != -1) return memo[n];
	if (n > 100) return memo[n] = n - 10;
	return memo[n] = f(f(n + 11));
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	memset(memo,-1,sizeof memo);
	int n;
	while (cin >> n && n) {
		int ans = f(n);
		cout << "f91(" << n << ") = " << ans << endl;
	}
	return 0;
}
