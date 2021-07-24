#include <bits/stdc++.h>
using namespace std;
const int MM = 7505;
int n, m, k, d[MM], vis[MM];
int main(){
	//freopen("walk.in", "r", stdin); freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k); 
	for (int i = 2; i <= n; i++) d[i] = 2019201997;
	for (int t = 0; t < n; t++){
		int mn = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && (!mn || d[mn] > d[i])) mn = i;
		vis[mn] = 1;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) d[i] = min(1LL * d[i], (2019201913LL * min(mn, i) + 2019201949LL * max(mn, i)) % 2019201997);
	}
	sort(d + 2, d + n + 1);
	printf("%d\n", d[n - k + 2]);
}
