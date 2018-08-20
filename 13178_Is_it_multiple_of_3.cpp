#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a % 3 == 1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
