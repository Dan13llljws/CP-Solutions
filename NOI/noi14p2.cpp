#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 15e4 + 5;
struct edge{int u, v, a, b;}edges[MM];
int n, m, ans = 1e9, dsu[MM], fa[MM], ch[MM][2], v[MM], id[MM], mx[MM], lz[MM];
inline int son(int x){return x == ch[fa[x]][1];}
inline bool isroot(int x){return ch[fa[x]][0] != x && ch[fa[x]][1] != x;}
inline void pushup(int x){
	mx[x] = v[x], id[x] = x;
	if (ch[x][0] && mx[ch[x][0]] > mx[x]) mx[x] = mx[ch[x][0]], id[x] = id[ch[x][0]];
	if (ch[x][1] && mx[ch[x][1]] > mx[x]) mx[x] = mx[ch[x][1]], id[x] = id[ch[x][1]];
}
inline void pushdown(int x){
	if (!lz[x]) return;
	lz[ch[x][0]] ^= 1, lz[ch[x][1]] ^= 1, lz[x] = 0;
	swap(ch[x][0], ch[x][1]);
}
void push(int x){
	if (!isroot(x)) push(fa[x]);
	pushdown(x);
}
void rotate(int x){
	int y = fa[x], z = fa[y], k = son(x);
	if (!isroot(y)) ch[z][son(y)] = x;
	fa[x] = z, ch[y][k] = ch[x][k ^ 1], fa[ch[x][k ^ 1]] = y;
	ch[x][k ^ 1] = y, fa[y] = x;
	pushup(y), pushup(x);
}
void splay(int x){
	push(x);
	for (; !isroot(x); rotate(x))
		if (!isroot(fa[x])) rotate(son(x) == son(fa[x]) ? fa[x] : x);
}
void access(int x){
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, pushup(x);
}
void makeroot(int x){access(x), splay(x), lz[x] ^= 1;}
int split(int x, int y){makeroot(x), access(y), splay(y); return id[y];}
void link(int x, int y){makeroot(x), fa[x] = y;}
void cut(int x, int y){makeroot(y), access(x), splay(x); fa[ch[x][0]] = 0, ch[x][0] = 0; pushup(x);}
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){dsu[Find(x)] = Find(y);}
int main(){
	n = re, m = re;
	for (int i = 1; i <= n; i++) dsu[i] = i;
	for (int i = 1; i <= m; i++) edges[i] = {re, re, re, re};
	sort(edges + 1, edges + 1 + m, [](edge a, edge b){return a.a < b.a;});
	for (int i = 1; i <= m; i++) v[i + n] = mx[i + n] = edges[i].b, id[i + n] = i + n;
	for (int i = 1; i <= m; i++){
		int uu = edges[i].u, vv = edges[i].v;
		if (Find(uu) == Find(vv)){
			int p = split(uu, vv);
			if (mx[p] > edges[i].b)
				cut(p, edges[p - n].v), cut(p, edges[p - n].u), link(i + n, uu), link(i + n, vv);
		} else unite(uu, vv), link(i + n, uu), link(i + n, vv);
		if (Find(1) == Find(n)) ans = min(ans, edges[i].a + mx[split(1, n)]);
	}
	printf("%d\n", ans == 1e9 ? -1 : ans);
}
