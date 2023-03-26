#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int n, r, c, k, sx, sy, ex, ey, b[17][17], d[17][17][7][7]; queue<array<int,4>> q;
int main(){
	n = re;
	while(n--){
		r = re, c = re, sx = re, sy = re, ex = re, ey = re, k = re; memset(b, 0, sizeof b);
		while(k--){
			int x1 = re, x2 = re, y1 = re, y2 = re;
			for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					b[i][j] = 1;
		}
		memset(d, inf, sizeof d); d[sx][sy][3][3] = 0, q.push({sx, sy, 0, 0});
		while(q.size()){
			int x = q.front()[0], y = q.front()[1], dx = q.front()[2], dy = q.front()[3]; q.pop();
			for (int ddx : {-1, 0, 1})
				for (int ddy : {-1, 0, 1}){
					int ndx = dx + ddx, ndy = dy + ddy, nx = x + ndx, ny = y + ndy;
					if (nx >= 0 && nx < r && ny >= 0 && ny < c && abs(ndx) < 4 && abs(ndy) < 4 && !b[nx][ny] && d[nx][ny][ndx+3][ndy+3] > d[x][y][dx+3][dy+3] + 1)
						d[nx][ny][ndx+3][ndy+3] = d[x][y][dx+3][dy+3] + 1, q.push({nx, ny, ndx, ndy});
				}
		}
		int ans = INF;
		for (int i = 0; i < 33; i++)
			for (int j = 0; j < 33; j++)
				ans = min(ans, d[ex][ey][i][j]);
		if (ans == INF) puts("No solution.");
		else printf("Optimal solution takes %d hops.\n", ans);
	}
}

