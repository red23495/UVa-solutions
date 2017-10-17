#include<bits/stdc++.h>

using namespace std;

int main(){
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		int root = sqrt(n);
		int last = n;
		long long res = 0;
		for(int i = 1; i <= root && n > 0; i++){
			int t = n / i;
			res += t;
			res += ((last - t)*(i - 1));
			//cout << t << ' ' << ((last - t)*(i - 1)) << endl;
			last = t;
		}
		if(n > 0) res += ((n/root)-root)*root;
		cout << res << endl;
	}
	return 0;
}
