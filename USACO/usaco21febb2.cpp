#include <bits/stdc++.h>
using namespace std;
int n, g[1005][1005], tot, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(){
	scanf("%d", &n); memset(g, -1, sizeof g);
	for (int i = 0, x, y; i < n; i++){
		scanf("%d%d", &x, &y); x++, y++;
		int cnt = 0;
		for (int k = 0; k < 4; k++){
			int nx = x + dx[k], ny = y + dy[k];
			if (~g[nx][ny]){
				g[nx][ny]++, cnt++;
				if (g[nx][ny] == 3) tot++;
				if (g[nx][ny] == 4) tot--;
			}
		}
		g[x][y] = cnt, tot += cnt == 3;
		printf("%d\n", tot);
	}
}
