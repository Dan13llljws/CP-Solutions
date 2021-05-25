#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2005;
int n, m, Q, x, y, d[MM<<1][MM<<1], g[MM][205], pf[MM][205]; ll ans; 
int get(int i, int l, int r){return pf[i][r] - pf[i][l - 1];}
int main(){
	n = re, m = re;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			g[i][j] = re;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			pf[i][j] = g[i][j] + pf[i][j - 1];
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++){
		int l = 2 * i - 1, r = 2 * i;
		d[l][l] = d[r][r] = 0, d[l][r] = get(i, 2, m), d[r][l] = get(i, 1, m - 1);
		for (int j = i - 1, ls = 0, rs = 0; j; j--){
			d[l][r] = min(d[l][r], ls + rs + pf[j][m] + g[i][m]);
			d[r][l] = min(d[r][l], ls + rs + pf[j][m] + g[i][1]);
			ls += g[j][1], rs += g[j][m];
		}
		for (int j = i + 1, ls = 0, rs = 0; j <= n; j++){
			d[l][r] = min(d[l][r], ls + rs + pf[j][m] + g[i][m]);
			d[r][l] = min(d[r][l], ls + rs + pf[j][m] + g[i][1]);
			ls += g[j][1], rs += g[j][m];
		}
	} 
	for (int i = 1; i <= n; i++){
		int l = 2 * i - 1, r = 2 * i;
		for (int j = i - 1; j; j--){
			int lc = 2 * j - 1, rc = 2 * j;
			d[l][lc] = min(d[l][2 * j + 1] + g[j][1], d[l][2 * j + 2] + d[rc][lc] + g[j][m]);
			d[l][rc] = min(d[l][2 * j + 2] + g[j][m], d[l][2 * j + 1] + d[lc][rc] + g[j][1]);
			d[r][lc] = min(d[r][2 * j + 1] + g[j][1], d[r][2 * j + 2] + d[rc][lc] + g[j][m]);
			d[r][rc] = min(d[r][2 * j + 2] + g[j][m], d[r][2 * j + 1] + d[lc][rc] + g[j][1]);
		}
		for (int j = i + 1; j <= n; j++){
			int lc = 2 * j - 1, rc = 2 * j;
			d[l][lc] = min(d[l][2 * j - 3] + g[j][1], d[l][2 * j - 2] + d[rc][lc] + g[j][m]);
			d[l][rc] = min(d[l][2 * j - 2] + g[j][m], d[l][2 * j - 3] + d[lc][rc] + g[j][1]);
			d[r][lc] = min(d[r][2 * j - 3] + g[j][1], d[r][2 * j - 2] + d[rc][lc] + g[j][m]);
			d[r][rc] = min(d[r][2 * j - 2] + g[j][m], d[r][2 * j - 3] + d[lc][rc] + g[j][1]);
		}
	} Q = re, ans = g[1][1], x = 1, y = 1;
	while(Q--){
		int a = re, b = re, res = 1e9;
		int d1 = pf[x][y - 1] + get(a, 2, b) + d[2 * x - 1][2 * a - 1];
		int d2 = get(x, y + 1, m) + get(a, b, m - 1) + d[2 * x][2 * a];
		int d3 = pf[x][y - 1] + get(a, b, m - 1) + d[2 * x - 1][2 * a];
		int d4 = get(x, y + 1, m) + get(a, 2, b) + d[2 * x][2 * a - 1];
		res = min({d1, d2, d3, d4});
		if (a == x) res = min(res, pf[a][max(b, y)] - pf[a][min(b, y) - 1] - g[a][y]);
		ans += res, x = a, y = b;
	} printf("%lld\n", ans);
}
