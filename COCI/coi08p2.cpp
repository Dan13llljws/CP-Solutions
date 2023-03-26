#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int MM = 30005;
int n, q, a, b, fa[MM], ch[MM][2], w[MM], v[MM], lz[MM], dsu[MM]; char cmd[10];
inline int son(int x){return x == ch[fa[x]][1];}
inline bool is_root(int x){return ch[fa[x]][0] != x && ch[fa[x]][1] != x;}
inline void push_up(int x){v[x] = w[x] + v[ch[x][0]] + v[ch[x][1]];}
inline void push_down(int x){
	if (!lz[x]) return;
	swap(ch[x][0], ch[x][1]);
	lz[ch[x][0]] ^= 1, lz[ch[x][1]] ^= 1;
	lz[x] = 0;
}
void push(int x){
	if (!is_root(x)) push(fa[x]);
	push_down(x);
}
void rotate(int x){
	int y = fa[x], z = fa[y], j = son(x);
	if (!is_root(y)) ch[z][son(y)] = x;
	fa[x] = z, ch[y][j] = ch[x][j ^ 1], fa[ch[x][j ^ 1]] = y;
	ch[x][j ^ 1] = y, fa[y] = x;
	push_up(y), push_up(x);
}
void splay(int x){
	push(x);
	for (; !is_root(x); rotate(x))
		if (!is_root(fa[x]))
			rotate(son(x) == son(fa[x]) ? fa[x] : x);
}
void access(int x){
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, push_up(x);
}
void make_root(int x){access(x); splay(x); lz[x] ^= 1;}
void link(int x, int y){make_root(x); fa[x] = y;}
int Find(int x){return x == dsu[x] ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){dsu[Find(x)] = Find(y);}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) w[i] = v[i] = re, dsu[i] = i;
	q = re;
	while(q--){
		scanf("%s", cmd); a = re, b = re;
		if (cmd[0] == 'b'){
			if (Find(a) == Find(b)){puts("no"); fflush(stdout);}
			else {unite(a, b), link(a, b); puts("yes"); fflush(stdout);}
		} else if (cmd[0] == 'p') access(a), splay(a), w[a] = b, push_up(a);
		else {
			if (Find(a) != Find(b)){puts("impossible"); fflush(stdout);}
			else {make_root(a), access(b), splay(b), printf("%d\n", v[b]); fflush(stdout);}
		}
	}
}
