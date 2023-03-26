#include <bits/stdc++.h>
using namespace std;
int n, ans, g[3005][3005]; queue<pair<int,int>> q;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int get(int x, int y){return g[x][y]&&((g[x - 1][y]!=0)+(g[x][y - 1]!=0)+(g[x + 1][y]!=0)+(g[x][y + 1]!=0)) == 3;}
int main(){
	scanf("%d", &n);
	while(n--){
		int x, y; scanf("%d%d", &x, &y); x += 1000, y += 1000;
		if (g[x][y] == 2) ans--, g[x][y] = 1;
		else {
			g[x][y] = 1;
			if (get(x, y)) q.push({x, y});
			for (int i = 0; i < 4; i++)
				if (get(x + dx[i], y + dy[i])) q.push({x + dx[i], y + dy[i]});
			while(q.size()){
				x = q.front().first, y = q.front().second; q.pop();
				if (!g[x][y]) continue;
				for (int i = 0; i < 4; i++){
					int nx = x + dx[i], ny = y + dy[i];
					if (!g[nx][ny]){
						ans++, g[nx][ny] = 2;
						if (get(nx, ny)) q.push({nx, ny});
						for (int j = 0; j < 4; j++)
							if (get(nx + dx[j], ny + dy[j])) q.push({nx + dx[j], ny + dy[j]});
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}	
