#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		int x = (a + b) >> 1;
		int y = (a - b) >> 1;
		if (y < 0 || x+y != a) cout << "impossible\n";
		else cout << x << ' ' << y << endl;
	}
	return 0;
}
