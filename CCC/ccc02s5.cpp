#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, cnt;
int main(){
	scanf("%d%d%d%d", &n, &m, &p, &q);
	for (int i = 1; i < 1e6; i++){
		double y = 1.0 * q * (n * i - p) / (n - p);
		int t = round(y / m);
		if (abs(t * m - y) < 5){
			cnt = i - 1 + y / m;
			if (y == t * m) cnt--;
			return 0 * printf("%d", cnt);
		}
	}
	puts("0");
}
