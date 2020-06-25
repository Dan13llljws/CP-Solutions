#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define f first
#define s second
const int mod = 1e9 + 7;
int r, c, dist[51][51], water[51][51]; pii st, ed; char g[51][51]; queue<pii> q;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
	r = re, c = re; ms(water, inf); ms(dist, inf);
	for (int i = 0; i < r; i++, getchar())
		for (int j = 0; j < c; j++){
			g[i][j] = getchar();
			if (g[i][j] == 'D') ed = {i, j};
			else if (g[i][j] == 'S') st = {i, j};
			else if (g[i][j] == '*') q.push({i, j}), water[i][j] = 0;
		}
	while(!q.empty()){
		int x = q.front().f, y = q.front().s; q.pop();
		for (int k = 0; k < 4; k++){
			int nx = dir[k][0] + x, ny = dir[k][1] + y;
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || water[nx][ny] <= water[x][y] + 1 || g[nx][ny] == 'X' || g[nx][ny] == 'D') continue;
			water[nx][ny] = water[x][y] + 1, q.push({nx, ny});
		}
	}
	q.push({st.f, st.s}), dist[st.f][st.s] = 0;
	while(!q.empty()){
		int x = q.front().f, y = q.front().s; q.pop();
		if (x == ed.f && y == ed.s) break;
		for (int k = 0; k < 4; k++){
			int nx = dir[k][0] + x, ny = dir[k][1] + y;
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || dist[nx][ny] <= dist[x][y] + 1 || g[nx][ny] == 'X' || water[nx][ny] <= dist[x][y] + 1) continue;
			dist[nx][ny] = dist[x][y] + 1, q.push({nx, ny});
		}
	}
	if (dist[ed.f][ed.s] == INF) puts("KAKTUS");
	else printf("%d", dist[ed.f][ed.s]);
}

