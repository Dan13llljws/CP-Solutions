#include <bits/stdc++.h>
using namespace std;
int t, m, n, f, k; double dp[101][101][202], c[101][101];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<pair<pair<int, int>, int>> q;
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &m, &n, &f, &k);
		if (f > m + n){puts("0.00"); continue;}
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n; j++){
				c[i][j] = 1e9;
				for (int j1 = 0; j1 <= f; j1++)
					dp[i][j][j1] = 1e9;
			}	
		for (int i = 0, a, b; i < k; i++){
			double new_val;
			scanf("%d%d", &a, &b), scanf("%lf", &new_val);
			c[a][b] = min(c[a][b], new_val);
		}
		dp[1][1][f] = 0; q.push({{1, 1}, f});
		while(!q.empty()){
			int x = q.front().first.first, y = q.front().first.second, fu = q.front().second; q.pop();
			if (c[x][y] != 1e9 && dp[x][y][fu + 1] > dp[x][y][fu] + c[x][y]){
				dp[x][y][fu + 1] = dp[x][y][fu] + c[x][y];
				q.push({{x, y}, fu + 1});
			}
			for (int i = 0; i < 4; i++){
				int nx = x + dir[i][0], ny = y + dir[i][1];
				if (nx && nx <= m && ny && ny <= n && dp[nx][ny][fu - 1] > dp[x][y][fu]){
					dp[nx][ny][fu - 1] = dp[x][y][fu];
					q.push({{nx, ny}, fu - 1});
				}
			}
		}
		if (dp[m][n][0] == 1e9) puts("Stranded on the shoulder");
		else printf("%.2f\n", dp[m][n][0]);
	}
}

