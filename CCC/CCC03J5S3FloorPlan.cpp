#include <bits/stdc++.h>
using namespace std;
int n, r, c, cnt; char g[65][65]; bool vis[65][65];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}; vector<int> v;
int dfs(int x, int y){
	if (x < 0 || x >= r || y < 0 || y >= c || vis[x][y] || g[x][y] == 'I') return 0;
	int ret = 1; vis[x][y] = 1;
	for (int i = 0; i < 4; i++) ret += dfs(x + dir[i][0], y + dir[i][1]);
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &r, &c);
	for (int i = 0; i < r; i++) scanf("%s", g[i]);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (!vis[i][j] && g[i][j] != 'I') v.push_back(dfs(i, j));
	sort(v.begin(), v.end(), greater<int>());
	for (int x : v) 
		if (n >= x) n -= x, cnt++;
		else break;
	printf("%d %s, %d square metre(s) left over", cnt, (cnt == 1 ? "room" : "rooms"), n);
}
