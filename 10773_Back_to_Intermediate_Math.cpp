#include<bits/stdc++.h>

using namespace std;

int main() {
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		double d, v, u;
		cin >> d >> v >> u;
		cout << "Case " << t << ": ";
		if (u == 0|| v == 0 || v >= u) { cout << "can't determine\n"; continue; }
		double fastest = d / u;
		double shortest = d / sqrt((u*u)-(v*v));
		cout << fixed << setprecision(3) <<shortest - fastest << endl;
	}
	return 0;
}
