#include <bits/stdc++.h>
using namespace std;
const int MM = 255;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, cnt, msz, ans, sz[MM*MM], s[MM*MM], c[MM*MM], dsu[MM*MM], g[MM][MM], p[MM][MM]; vector<int> f[1000005]; vector<pair<int,int>> edges;
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){
	x = Find(x), y = Find(y);
	if (x == y) return;
	sz[y] += sz[x], dsu[x] = y, ans = max(ans, sz[y]);
}
int main(){
	//freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			scanf("%d", &g[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (p[i][j]) continue;
			cnt++, dsu[cnt] = cnt, c[cnt] = g[i][j], f[g[i][j]].push_back(cnt);
			queue<pair<int,int>> q;
			q.push({i, j}), p[i][j] = cnt;
			while(!q.empty()){
				int x = q.front().first, y = q.front().second; q.pop();
				sz[cnt]++, s[cnt]++;
				for (int k = 0; k < 4; k++){
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (!p[nx][ny] && g[nx][ny] == c[cnt]) p[nx][ny] = cnt, q.push({nx, ny});
					else if (p[nx][ny] && g[nx][ny] != c[cnt]) edges.push_back({cnt, p[nx][ny]}); 
				}
			}
			msz = max(msz, sz[cnt]);
		}
	for (auto &e : edges) if (c[e.first] < c[e.second]) swap(e.first, e.second);
	ans = msz;
	sort(edges.begin(), edges.end(), [&](pair<int,int> a, pair<int,int> b){
		return c[a.first] == c[b.first] ? c[a.second] < c[b.second] : c[a.first] < c[b.first];
	});
	int pp = 0;
	for (int i = 0; i < (int)edges.size(); i++){
		if (i && make_pair(c[edges[i].first], c[edges[i].second]) != make_pair(c[edges[i - 1].first], c[edges[i - 1].second])){
			for (int j = pp; j < i; j++){
				int u = edges[j].first, v = edges[j].second;
				sz[u] = s[u], sz[v] = s[v], dsu[u] = u, dsu[v] = v; 
			}
			pp = i;
		}
		unite(edges[i].first, edges[i].second);
	}
	printf("%d\n%d\n", msz, ans);
}
			
	
