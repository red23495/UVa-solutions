#include<bits/stdc++.h>

using namespace std;

int main() {
	cout << "PERFECTION OUTPUT\n";
	int n;
	while (cin >> n && n) {
		int pivot = sqrt(n);
		int sum = 1;
		for (int i = 2; i <= pivot; i++) {
			if (!(n%i)) {
				sum += i;
				if(i != n/i) sum += n / i;
			}
		}
		if (n == 1) sum = 0;
		cout << setw(5) << n << "  ";
		if (sum == n) cout << "PERFECT\n";
		else if (sum < n) cout << "DEFICIENT\n";
		else cout << "ABUNDANT\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
