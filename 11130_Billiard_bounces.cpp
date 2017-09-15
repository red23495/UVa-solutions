#include<bits/stdc++.h>

using namespace std;

constexpr double PI = 3.14159265359;

int main() {
	double a, b, v, A, t;
	while (cin >> a >> b >> v >> A >> t && a) {
		double distance = (v / 2)*t;
		double projA = distance*cos(A*PI / 180), projB = distance*sin(A*PI / 180);
		int hitX = 0, hitY = 0;
		if (projA >= (a / 2)) {
			hitX++; projA -= (a / 2);
		}
		hitX += (int)(projA / a);
		if (projB >= (b / 2)) {
			hitY++; projB -= (b / 2);
		}
		hitY += (int)(projB / b);
		cout << hitX << ' ' << hitY << endl;
	}
	return 0;
}
