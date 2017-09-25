#include<bits/stdc++.h>

using namespace std;

double height,top_part,bottom_part;

struct cord {
	double x, y;
};

cord find_cord(int cell) {
	int level = sqrt(cell);
	double x = level * height;
	if ((level & 1 && cell & 1) || (!(level & 1) && !(cell & 1))) x += top_part;
	else x += bottom_part;
	double offset = cell - (level*level);
	double y = (offset - level)*0.5;
	return { x,y };
}

double dist(cord a, cord b) {
	return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));
}

int main() {
	height = sqrt(3) / 2;
	bottom_part = height / 3;
	top_part = 2*bottom_part;
	int a, b;
	cout << fixed << setprecision(3);
	while (cin >> a >> b) {
		cord p, q;
		p = find_cord(a);
		q = find_cord(b);
		cout << dist(p,q) << endl;
	}
	
	return 0;
}
