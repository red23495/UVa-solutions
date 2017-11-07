#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
	int test = 1;
	ull n;
	while (cin >> n && n) {
		ull lo = 4, hi = 3200000000, ans = 0;
		while (lo <= hi) {
			ull mid = (lo + hi) / 2;
			ull val;
			if (mid & 1) {
				val = mid * ((mid - 3) >> 1);
			}
			else {
				val = (mid >> 1)*(mid - 3);
			}
			if(val == n) {
				ans = mid;
				break;
			}else if(val < n){
				lo = mid + 1;
			}
			else {
				hi = mid - 1;
			}
		}
		if (!ans) ans = lo;
		cout << "Case " << test++ << ": " << ans << endl;
	}
	return 0;
}
