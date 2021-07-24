#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
const int MM = 45, mod = 1e9 + 7;
struct tri{int a, b, c;};
int n, ans, dp[MM][MM][MM], cnt[MM][MM][MM]; pii p[MM]; ll fac[MM], perm[MM][MM], ch[MM][MM];
int cross(pii a, pii b, pii c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
}
bool inside(pii pt, pii a, pii b, pii c){
	return cross(a, b, c) == cross(a, b, pt) && cross(a, c, b) == cross(a, c, pt) && cross(b, c, a) == cross(b, c, pt);
}
int area(pii a, pii b, pii c){
	return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y);
}
int main(){
	scanf("%d", &n); vector<tri> t; fac[0] = ch[0][0] = perm[0][0] = 1;
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++){
				t.push_back({i, j, k});
				for (int i1 = 0; i1 < n; i1++)
					if (i1 != j && i1 != j && i1 != k && inside(p[i1], p[i], p[j], p[k]))
						cnt[i][j][k]++;
			}
	sort(t.begin(), t.end(), [&](tri a, tri b){return area(p[a.a], p[a.b], p[a.c]) > area(p[b.a], p[b.b], p[b.c]);});
	if (cnt[t[0].a][t[0].b][t[0].c] != n - 3) return 0 * puts("0");
	for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod, perm[i][0] = ch[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ch[i][j] = (ch[i - 1][j - 1] + ch[i - 1][j]) % mod, perm[i][j] = ch[i][j] * fac[j] % mod;
	dp[t[0].a][t[0].b][t[0].c] = 1;
	for (int i = 0; i < (int)t.size(); i++){
		int a = t[i].a, b = t[i].b, c = t[i].c;
		for (int j = 0; j < n; j++)
			if (j != a && j != b && j != c && inside(p[j], p[a], p[b], p[c])){
				for (int k = 0; k < 3; k++){
					vector<int> pt = {a, b, c}; pt[k] = j; sort(pt.begin(), pt.end());
					dp[pt[0]][pt[1]][pt[2]] = (dp[pt[0]][pt[1]][pt[2]] + dp[a][b][c] * perm[n - cnt[pt[0]][pt[1]][pt[2]] - 4][cnt[a][b][c] - cnt[pt[0]][pt[1]][pt[2]] - 1]) % mod;
				}
			}
		ans = (ans + dp[a][b][c] * perm[n - 3][cnt[a][b][c]] * 6) % mod;
	} printf("%d\n", ans);
}
