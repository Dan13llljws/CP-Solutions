#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e5 + 5;
#define lc ch[x][0]
#define rc ch[x][1]
int N, bit[MM], fa[MM], ch[MM][2], v[MM], sz[MM]; vector<pii> p; vector<int> comp;
inline int son(int x){return x == ch[fa[x]][1];}
inline bool isroot(int x){return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
inline void pushup(int x){sz[x] = 1 + sz[lc] + sz[rc];}
inline void pushdown(int x){v[lc] = v[rc] = v[x];}
void push(int x){
	if (!isroot(x)) push(fa[x]);
	pushdown(x);
}
void rotate(int x){
	int y = fa[x], z = fa[y], k = son(x);
	if (!isroot(y)) ch[z][son(y)] = x;
	fa[x] = z, ch[y][k] = ch[x][k ^ 1], fa[ch[x][k ^ 1]] = y;
	ch[x][k ^ 1] = y, fa[y] = x; pushup(y), pushup(x);
}
void splay(int x){
	push(x);
	for (; !isroot(x); rotate(x))
		if (!isroot(fa[x])) rotate(son(x) == son(fa[x]) ? fa[x] : x);
}
void access(int x){
	for (int y = 0; x; x = fa[y = x])
		splay(x), rc = y, pushup(x), p.push_back({v[x], sz[lc] + 1});
}
void update(int x, int val){
	for (; x <= N; x += x & -x) bit[x] += val;
}
int query(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	N = re;
	for (int i = 1; i <= N; i++) comp.push_back(v[i] = re);
	sort(comp.begin(), comp.end()); comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
	for (int i = 1; i <= N; i++) v[i] = lower_bound(comp.begin(), comp.end(), v[i]) - comp.begin() + 1;
	for (int i = 1; i <= N; i++) sz[i] = 1;
	for (int i = 1; i < N; i++){
		int a = re, b = re; ll ans = 0;
		access(a);
		for (int j = 0; j < (int)p.size(); j++){
			ans += 1LL * query(p[j].first - 1) * p[j].second;
			update(p[j].first, p[j].second);
		}
		for (int j = 0; j < (int)p.size(); j++) update(p[j].first, -p[j].second);
		p.clear();
		printf("%lld\n", ans);
		splay(a), fa[b] = a, ch[a][1] = b, v[a] = v[b];
	}
}

