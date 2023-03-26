#include <bits/stdc++.h>
using namespace std;
int n, ans, p[160005], w[160005], vis[22][22], in[160005]; char g[22][22]; vector<int> adj[160005];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int hsh(int a, int b, int c, int d){a--, b--, c--, d--; return ((a * n + b) * n + c) * n + d;}
int main(){
	//freopen("where.in", "r", stdin); freopen("where.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int i1 = i; i1 <= n; i1++)
				for (int j1 = j; j1 <= n; j1++){
					for(int i2 = i; i2 <= i1; i2++)
						for (int j2 = j; j2 <= j1; j2++)
							vis[i2][j2] = 0;
					queue<pair<int,int>> q; vector<char> v;
					for (int i2 = i; i2 <= i1; i2++)
						for (int j2 = j; j2 <= j1; j2++){
							if (vis[i2][j2]) continue;
							q.push({i2, j2}), vis[i2][j2] = 1, v.push_back(g[i2][j2]);
							while(q.size()){
								int x = q.front().first, y = q.front().second; q.pop();
								for (int k = 0; k < 4; k++){
									int nx = x + dx[k], ny = y + dy[k];
									if (nx < i || ny < j || nx > i1 || ny > j1 || g[nx][ny] != g[x][y] || vis[nx][ny]) continue;
									q.push({nx, ny}), vis[nx][ny] = 1;
								}
							}
						}
					sort(v.begin(), v.end());
					int src = hsh(i, j, i1, j1), a = hsh(i + 1, j, i1, j1), b = hsh(i, j, i1 - 1, j1), c = hsh(i, j + 1, i1, j1), d = hsh(i, j, i1, j1 - 1);
					if ((int)v.size() > 2 && ((v[0] == v[v.size() - 2] && v[v.size() - 2] != v.back()) || (v[0] != v[1] && v[1] == v.back()))) w[src] = 1;
					if (i != i1) adj[src].push_back(a), adj[src].push_back(b), in[a]++, in[b]++;
					if (j != j1) adj[src].push_back(c), adj[src].push_back(d), in[c]++, in[d]++;
				}
	queue<int> q;
	q.push(hsh(1, 1, n, n));
	while(q.size()){
		int src = q.front(); q.pop();
		if (!p[src] && w[src] == 1) ans++;
		w[src] += p[src];
		for (int v : adj[src]){
			p[v] += w[src];
			if (!--in[v]) q.push(v);
		}
	}
	printf("%d\n", ans);
}
	
				
