#include <bits/stdc++.h>
using namespace std;
int T, st, ed, g[13][13], mx[13];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &st, &ed); memset(g, 0, sizeof g); memset(mx, 0, sizeof mx);
		int t = 6, b = 6, l = 6, r = 6, d = 1, td = 0, x = 6, y = 6, cur = 0; bool flag = 0;
		g[x][y] = st;
		for (int i = st + 1; i <= ed; i++){
			x += dir[cur%4][0], y += dir[cur%4][1];
			g[x][y] = i, td++;
			if (td == d) d += flag, flag ^= 1, cur++, td = 0;
			t = min(t, x), b = max(b, x), l = min(l, y), r = max(r, y);
		}
		for (int i = l; i <= r; i++)
			for (int j = t; j <= b; j++)
				mx[i] = max(mx[i], g[j][i]);
		for (int i = t; i <= b; i++){
			for (int j = l; j <= r; j++){
				if (!g[i][j]){
					if (mx[j] < 10) printf(" ");
					else printf("  ");
				}
				else if (g[i][j] < 10 && mx[j] >= 10) printf(" %d", g[i][j]);
				else printf("%d", g[i][j]);
				putchar(j == r ? '\n' : ' ');
			}
		}
		if (T) puts("");
	}
}
