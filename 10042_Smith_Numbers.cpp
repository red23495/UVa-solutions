#include<bits/stdc++.h>

using namespace std;

vector<int> primes;

int sum_of_digits(int n) {
	int sum = 0;
	while (n) {
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

int main(){
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		int ans = 0;
		for(int i = n+1; !ans ; i++){
			int fsum = 0,flag = 0,num = i;
			int dig = sum_of_digits(num);
			for (int j = 2; j <= sqrt(num); j++) {
				while (!(num%j)) {
					fsum += sum_of_digits(j);
					num /= j;
					//cout << num << ' ' <<j << endl;
					flag++;
				}
			}
			if (num != 1) { fsum += sum_of_digits(num); flag++; }
			if (dig == fsum && flag > 1) ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}
