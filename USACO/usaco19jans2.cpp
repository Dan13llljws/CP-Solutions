#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, area, ans, sz, p; char g[MM][MM]; bool v[MM][MM]; queue<pair<int,int>> q;
int main(){
	//freopen("perimeter.in", "r", stdin); freopen("perimeter.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			if (v[i][j] || g[i][j] == '.') continue;
			v[i][j] = 1, q.push({i, j}), sz = 0, p = 0;
			while(!q.empty()){
				int x = q.front().first, y = q.front().second; q.pop();
				sz++;
				for (int k = 0; k < 4; k++){
					int nx = x + dx[k], ny = y + dy[k];
					if (g[nx][ny] != '#') p++;
					if (!nx || !ny || nx > n || ny > n || v[nx][ny] || g[nx][ny] == '.') continue;
					v[nx][ny] = 1, q.push({nx, ny});
				}
			}
			if (sz > area) area = sz, ans = p;
			else if (sz == area) ans = min(ans, p);
		}
	printf("%d %d\n", area, ans);
} 
				
