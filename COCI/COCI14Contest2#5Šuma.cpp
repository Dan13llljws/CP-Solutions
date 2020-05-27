#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, base = 131, MM = 705;
struct edge{int a, b; long double w;} edges[MM * MM * 2];
int n, ans, tot, qid,  h[MM][MM], v[MM][MM], id[MM * MM], dsu[2][MM * MM], sz[2][MM * MM], rk[2][MM * MM];
int dir[2][2] = {{0, 1}, {1, 0}};
int get(int x, int y){return x * n + y;}
void update(int x){if (id[x] != qid) id[x] = qid, sz[1][x] = sz[0][x], dsu[1][x] = dsu[0][x], rk[1][x] = rk[0][x];}
int Find(int x, bool u){
	if (u) update(x);
	return dsu[u][x] == x ? x : dsu[u][x] = Find(dsu[u][x], u);
}
void unite(int x, int y, bool u){
	x = Find(x, u), y = Find(y, u);
	if (u) update(x), update(y);
	if (rk[u][x] < rk[u][y]) sz[u][y] += sz[u][x], dsu[u][x] = y;
	else if (rk[u][x] > rk[u][y]) sz[u][x] += sz[u][y], dsu[u][y] = x;
	else sz[u][x] += sz[u][y], dsu[u][y] = x, rk[u][x]++;
}
bool cmp(edge a, edge b){return a.w < b.w;}
int valid(int i1, int j1, int i2, int j2){
	int a = h[i1][j1], b = v[i1][j1], c = h[i2][j2], d = v[i2][j2];
	if (a == c && b == d) return 2;
	if ((a < c && b > d) || (a > c && b < d)) return 1;
	return 0;
}
long double get_weight(int i1, int j1, int i2, int j2){
	long double a = h[i1][j1], b = v[i1][j1], c = h[i2][j2], d = v[i2][j2];
	if (a == c && b == d) return a;
	return b * (c - a) / (b - d) + a;
}
int main(){
	n = re;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			h[i][j] = re;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v[i][j] = re;
	for (int i = 0; i < n * n; i++) dsu[0][i] = i, sz[0][i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 2; k++){
				int ni = i + dir[k][0], nj = j + dir[k][1];
				if (ni >= n || nj >= n) continue;
				int a = valid(i, j, ni, nj), x = get(i, j), y = get(ni, nj);
				if (a == 1) edges[++tot] = {x, y, get_weight(i, j, ni, nj)};
				else if (a == 2 && Find(x, 0) != Find(y, 0)) unite(x, y, 0), ans = max(ans, sz[0][Find(y, 0)]);
			}
	sort(edges + 1, edges + tot + 1, cmp);
	for (int i = 1; i <= tot; i++){ 
		int a = edges[i].a, b = edges[i].b; long double w = edges[i].w;
		if (w != edges[i - 1].w) qid++;
		if (Find(a, 1) != Find(b, 1)) unite(b, a, 1);
		ans = max(ans, sz[1][Find(b, 1)]);
	}
	printf("%d", ans);
}
