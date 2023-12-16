#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int n, m, s, t, d[MM][MM]; vector<int> adj[MM];
double dp[MM][MM];
double rec(int a, int b) {
	double &ret = dp[a][b];
	if (ret != -1) return ret;
	if (a == b) return ret = 0;
	for (int _ = 0; _ < 2; _++)
		for (int v : adj[a]) {
			if (d[v][b] < d[a][b]) {
				a = v;
				break;
			}
		}
	ret = 1;
	if (a == b) return ret;
	double p = 1 + adj[b].size();
	ret += rec(a, b) / p;
	for (int v : adj[b]) ret += rec(a, v) / p;
	return ret;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = -1;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) {
		queue<int> q; q.push(i);
		d[i][i] = 0;
		while(q.size()) {
			int u = q.front(); q.pop();
			for (int v : adj[u]) {
				if (d[i][v] > d[i][u] + 1) d[i][v] = d[i][u] + 1, q.push(v);
			}
		}
	}
	printf("%.3f\n", rec(s, t));
}
