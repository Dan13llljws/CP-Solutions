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
int n, m, dist[505][505]; pii st, ed; char g[505][505]; bool vis[505][505]; queue<pii> q;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main(){
	n = re, m = re; ms(dist, inf); 
	for (int i = 0; i < n; i++, getchar())
		for (int j = 0; j < m; j++){
			g[i][j] = getchar();
			if (g[i][j] == '+') q.push({i, j}), dist[i][j] = 0;
			if (g[i][j] == 'V') st = {i, j};
			if (g[i][j] == 'J') ed = {i, j};
		}
	while(!q.empty()){
		int x = q.front().f, y = q.front().s; q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] <= dist[x][y] + 1) continue;
			dist[nx][ny] = dist[x][y] + 1, q.push({nx, ny});
		}
	}
	for (int i = dist[st.f][st.s]; i >= 0; i--){
		ms(vis, 0); vis[st.f][st.s] = 1; q.push({st.f, st.s});
		while(!q.empty()){
			int x = q.front().f, y = q.front().s; q.pop();
			if (x == ed.f && y == ed.s) return 0 * printf("%d", i);
			for (int k = 0; k < 4; k++){
				int nx = x + dir[k][0], ny = y + dir[k][1];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] < i || vis[nx][ny]) continue;
				vis[nx][ny] = 1, q.push({nx, ny});
			}
		}
	}
}
