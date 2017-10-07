#include<bits/stdc++.h>

using namespace std;
using ld = long double;

int main() {
	int n;
	while (cin >> n) {
		ld up = log2l(n);
		ld down = log2l(n+1);
		ld f = log2l(10);
		int t = log10l(n)+2;
		int ans = 0;
		while (!ans) {
			ld val1 = up + t*f;
			ld val2 = down + t*f;
			if (ceill(val1) == floorl(val2)) ans = val2;
			t++;
		}
		cout << ans << endl;
	}
	return 0;
}
