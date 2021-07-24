#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int n, d, ans, dist[MM][MM], wall[MM][MM]; char g[MM][MM]; queue<pair<int, int>> q;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
	scanf("%d%d", &n, &d); 
	memset(dist, 0x3f, sizeof dist); memset(wall, 0x3f, sizeof wall);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j] == '#') wall[i][j] = 0, q.push({i, j});
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (nx && ny && nx <= n && ny <= n && wall[nx][ny] > wall[x][y] + 1)
				wall[nx][ny] = wall[x][y] + 1, q.push({nx, ny});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j] == 'S') dist[i][j] = 0, q.push({i, j});
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		if (dist[x][y] / d + 1 > wall[x][y]) continue;
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (g[nx][ny] != '#' && dist[nx][ny] > dist[x][y] + 1)
				dist[nx][ny] = dist[x][y] + 1, q.push({nx, ny});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dist[i][j] != 0x3f3f3f3f && dist[i][j] / d <= wall[i][j])
				q.push({i, j}), dist[i][j] = wall[i][j];
			else dist[i][j] = 0;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if (g[nx][ny] != '#' && dist[nx][ny] < dist[x][y] - 1)
				dist[nx][ny] = dist[x][y] - 1, q.push({nx, ny});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dist[i][j]) ans++;
	printf("%d\n", ans);
}
