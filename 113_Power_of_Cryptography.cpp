#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	double a, b;
	while (cin >> a >> b) {
		double ans = pow(b, 1/a);
		cout << ans << endl;
	}
	return 0;
}
