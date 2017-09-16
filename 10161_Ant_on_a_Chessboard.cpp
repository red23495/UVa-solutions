#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
int main() {
	int n;
	while (cin >> n && n) {
		int root = ceil(sqrt(n));
		int start = n - pow(root - 1, 2);
		int i, j;
		if (start <= root) { i = root; j = start; }
		else { i = 2 * root - start; j = root; }
		if (root & 1) cout << i << ' ' << j << endl;
		else cout << j << ' ' << i << endl;
	}
	return 0;
}
