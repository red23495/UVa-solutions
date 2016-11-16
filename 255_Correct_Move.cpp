#include<iostream>
#include<cmath>
using namespace std;

bool between(int first, int middle, int last){
	return ((first < last)? first < middle && middle < last : last < middle && middle < first);
}

bool corner(int k, int q){
	return (k==0 && q==9) ||(k==7 && q==14) ||(k== 56 && q==49) ||(k==63 && q==54);
}

int main(){
	int k,q,m;
	while(cin >> k >> q >> m){
		if(k == q){
			cout << "Illegal state\n";
		}
		else{
			int kx,ky,qx,qy,mx,my;
			kx = k/8; qx = q/8; mx = m/8;
			ky = k%8; qy = q%8; my = m%8;
			if(q == m || k == m || !(qx == mx || qy == my)) cout << "Illegal move\n";
			else {
				if((qx == mx && kx == mx && between(qy,ky,my)) ||(qy == my && ky == my && between(qx,kx,mx)))
					cout << "Illegal move\n";
				else if( (kx == mx && abs(ky - my)==1) || (ky == my && abs(kx - mx)==1) )
					cout << "Move not allowed\n";
				else if(corner(k,m)) cout << "Stop\n";
				else cout << "Continue\n";
			}
		}
	}
	return 0;
}

