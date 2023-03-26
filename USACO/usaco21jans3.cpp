#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int n, ans, g[MM][MM];
void solve(){
	int res = 0;
	for (int i = 1; i <= n; i++){
		int s[2] = {0};
		for (int j = 1; j <= n; j++) s[j & 1] += g[i][j];
		res += max(s[0], s[1]);
	}
	ans = max(res, ans);	
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	solve();
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			swap(g[i][j], g[j][i]);
	solve();
	printf("%d\n", ans);
}
	
