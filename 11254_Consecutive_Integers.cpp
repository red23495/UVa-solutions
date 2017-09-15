#include<bits/stdc++.h>

using namespace std;

int main() {
	double n;
	while (cin >> n && n > 0) {
		int up = ceil(sqrt(2.0*n));
		int low,hi;
		low = hi = n;
		for (int i = up; i > 0; i--) {
			int a = (n / i) - (i - 1) / 2;
			if (a == 0) continue;
			int sum = a*i + (i - 1)*i*0.5;
			//cout << a << ' ' << i << ' ' << sum << endl;
			if (sum == n) {
				low = a; hi = (a + i - 1); break;
			}
		}
		cout << int(n) << " = " << low << " + ... + " << hi << endl;
	}
	return 0;
}
