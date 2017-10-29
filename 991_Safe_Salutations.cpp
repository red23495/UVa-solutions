#include<bits/stdc++.h>

using namespace std;

int main() {
	int cat[11];
	cat[0] = 1;
	for (int i = 1; i <= 10; i++) {
		cat[i] = ((2.0 * i*(2.0 * i - 1)) / (i*(i + 1.0)))*cat[i - 1];
	}
	int n;
	bool begin = true;
	while (cin >> n) {
		if (begin) begin = false;
		else cout << endl;
		cout << cat[n] << endl;
	}
	return 0;
}
