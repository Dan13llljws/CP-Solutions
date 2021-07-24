#include <bits/stdc++.h>
using namespace std;
int n, xx[2505], yy[2505], psa[2505][2505]; long long ans; pair<int, int> p[2505]; 
int get(int a, int b, int c, int d){return psa[a][b] - psa[c - 1][b] - psa[a][d - 1] + psa[c - 1][d - 1];}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &xx[i], &yy[i]), p[i] = {xx[i], yy[i]};
	sort(p, p + n), sort(xx, xx + n), sort(yy, yy + n); 
	for (int i = 0; i < n; i++){
		p[i].first = lower_bound(xx, xx + n, p[i].first) - xx + 1;
		p[i].second = lower_bound(yy, yy + n, p[i].second) - yy + 1;
		psa[p[i].first][p[i].second]++;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++){
			int l = get(p[j].first, min(p[i].second, p[j].second), p[i].first, 1);
			int r = get(p[j].first, n, p[i].first, max(p[i].second, p[j].second));
			ans += 1LL * l * r;
		}
	printf("%lld\n", ans + 1);
}
