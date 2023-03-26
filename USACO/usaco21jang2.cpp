#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4 + 5;
int n, k, d[MM], t[MM], l[55][MM], r[55][MM]; char g[55][55]; priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", t + i);
	for (int i = 1; i <= k; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= k; j++) l[j][i] = j == t[i - 1] ? i - 1 : l[j][i - 1];
	for (int i = n; i >= 0; i--)
		for (int j = 1; j <= k; j++) r[j][i] = j == t[i + 1] ? i + 1 : r[j][i + 1];
	memset(d, 0x3f, sizeof d); d[1] = 0, q.push({0, 1});
	while(q.size()){
		int src = q.top().second, dis = q.top().first; q.pop();
		if (dis > d[src]) continue;
		for (int i = 1; i <= k; i++){
			if (g[t[src]][i] == '0') continue;
			if (l[i][src] && d[l[i][src]] > d[src] + src - l[i][src])
				d[l[i][src]] = d[src] + src - l[i][src], q.push({d[l[i][src]], l[i][src]});
			if (r[i][src] && d[r[i][src]] > d[src] + r[i][src] - src)
				d[r[i][src]] = d[src] + r[i][src] - src, q.push({d[r[i][src]], r[i][src]});
			if (l[i][n + 1] && d[l[i][n + 1]] > d[src] + abs(l[i][n + 1] - src))
				d[l[i][n + 1]] = d[src] + abs(l[i][n + 1] - src), q.push({d[l[i][n + 1]], l[i][n + 1]});
		}
	}
	printf("%d\n", d[n] == 0x3f3f3f3f ? -1 : d[n]);
}
