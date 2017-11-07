#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull memo[1000001];



int main() {
	for (ull i = 1; i <= 1000000; i++) {
		memo[i] = memo[i - 1] + i*(i - 1);
	}
	ull x, y;
	while (cin >> x >> y && x) {
		ull ans = x * (y - 1) * y + y * (x - 1)* x;
		//cout << ans << endl;
		ull lo = min(x, y);
		ull hi = max(x, y);
		ull diag = hi - lo + 1;
		//cout << diag << endl;
		ull offset = diag*lo*(lo - 1);
		//cout << offset << endl;
		offset += (2 * memo[lo - 1]);
		//cout << offset << endl;
		ans += (2*offset);
		cout << ans << endl;
	}
	return 0;
}
