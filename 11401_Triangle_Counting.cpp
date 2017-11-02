#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
	ull *mem = new ull[1000001];
	mem[1] = mem[2] = 0;
	for (ull i = 3; i <= 1000000; i++) {
		if (i & 1) {
			mem[i] = (((i - 1)*(i - 3)) >> 2) + mem[i - 1];
		}
		else {
			ull mul = (i - 2) >> 1;
			mem[i] = mul*mul + mem[i - 1];
		}
	}
	int n;
	while (cin >> n && n > 2) {
		cout << mem[n] << endl;
	}
	delete[] mem;
	return 0;
}
