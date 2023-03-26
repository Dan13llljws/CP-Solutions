#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
const int MM = 105;
int n, m, ans, dp[MM][MM]; pii p1[MM], p2[MM], org = {0, 0};
int cross(pii a, pii b, pii c){
	return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x) > 0;
}
bool in(pii pt, pii a, pii b, pii c){
	return cross(a, b, pt) == cross(a, b, c) && cross(a, c, b) == cross(a, c, pt) && cross(b, c, a) == cross(b, c, pt);
}
int main(){
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++) scanf("%d%d", &p1[i].x, &p1[i].y);
	for (int i = 0; i < m; i++) scanf("%d%d", &p2[i].x, &p2[i].y);
	sort(p1, p1 + n, [](pii a, pii b){return atan2(a.y, a.x) < atan2(b.y, b.x);});
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			int cnt = 2; dp[i][j] = -1e9;
			for (int k = 0; k < n; k++)
				if (k != i && k != j && in(p1[k], org, p1[i], p1[j])) cnt++;
			for (int k = 0; k < m; k++)
				if (in(p2[k], org, p1[i], p1[j])) cnt--;
			dp[i][j] = cnt;
			for (int k = 0; k < j; k++)
				if (cross(p1[k], p1[j], p1[i]))
					dp[i][j] = max(dp[i][j], dp[j][k] + cnt - 1);
			ans = max(ans, dp[i][j]);
		}
	} printf("%d\n", ans);
}
