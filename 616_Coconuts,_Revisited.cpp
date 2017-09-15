#include<bits/stdc++.h>

using namespace std;

bool check(int coconut, int people, int pass) {
	//cout << coconut << ' ' << people << ' ' << pass << endl;
	int temp = coconut;
	if (pass) temp--;
	if (!pass) {
		if (temp%people) return false;
		else return true;
	}
	if (temp%people) return false;
	temp -= (temp / people);
	return check(temp,people,pass-1);
}

int main() {
	int n;
	while (cin >> n && n >= 0){
		bool sol = false;
		for (int i = 10; i > 1; i--) {
			if (check(n, i, i)) {
				cout << n <<" coconuts, "<< i <<" people and 1 monkey\n";
				sol = true;
				break;
			}
		}
		if (!sol) cout << n << " coconuts, no solution\n";
	}
	return 0;
}
