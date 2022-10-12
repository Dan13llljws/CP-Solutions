#include <bits/stdc++.h>
using namespace std;
int R, C, K, ans;
int query(int x, int y){
	int ret;
	cout << "? " << x << ' ' << y << endl;
	cin >> ret; return ret;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> K;
	int rl = 1, rr = R, cl = 1, cr = C;
	while(rl < rr || cl < cr){
		int rm = rl + rr >> 1, cm = cl + cr >> 1, f1, f2;
		f1 = query(rm, cm);
		if (rl < rr){
			f2 = query(rm + 1, cm);
			if (f2 > f1) rr = rm;
			else rl = rm + 1;
		}
		if (cl < cr){
			f2 = query(rm, cm + 1);
			if (f2 > f1) cr = cm;
			else cl = cm + 1;
		}
	}
	ans = query(rl, cl);
	cout << "! " << ans << endl;
	return 0;
}
