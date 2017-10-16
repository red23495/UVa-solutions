#include<bits/stdc++.h>

using namespace std;

int to_int(string s){
	int base = pow(2, s.length());
	int ret = 0;
	for(int i = 0; i < s.length(); i++){
		int t = 0;
		t = s[i] - '0';
		ret += (t*(base-1));
		base /= 2;
	}
	return ret;
}

int main(){
	string s;
	while(cin >> s && s != "0"){
		cout << to_int(s) << endl;
	}
	return 0;
}
