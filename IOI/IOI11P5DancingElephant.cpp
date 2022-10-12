#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 3e5 + 5;
#define lc ch[x][0]
#define rc ch[x][1]
int fa[MM], ch[MM][2], v[MM], val[MM], lz[MM];
inline int son(int x){return x == ch[fa[x]][1];}
inline bool isroot(int x){return x != ch[fa[x]][0] && x != ch[fa[x]][1];}
inline void pushup(int x){
	val[x] = v[x];
	if (lc) val[x] += val[lc];
	if (rc) val[x] += val[rc];
}
inline void pushdown(int x){
	if (lz[x]) lz[x] = 0, lz[lc] ^= 1, lz[rc] ^= 1, swap(lc, rc);
}
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
		splay(x), rc = y, pushup(x);
}
void makeroot(int x){access(x), splay(x), lz[x] ^= 1;}
int findroot(int x){access(x), splay(x); while(lc) x = lc; return x;}
int split(int x, int y){x++, y++, makeroot(x), access(y), splay(y); return val[y];}
void link(int x, int y){x++, y++, makeroot(x), fa[x] = y;}
void cut(int x, int y){x++, y++, makeroot(y), access(x), splay(x), fa[lc] = 0, lc = 0, pushup(x);}
#undef lc
#undef rc
int n, l, x[MM]; set<pii> s;
void init(int N, int L, int X[]){
	n = N, l = L;
	for (int i = 0; i < n; i++){
		x[i] = X[i], v[i + 1] = 1;
		s.insert({x[i], i}), s.insert({x[i] + l, i + n}), link(i, i + n);
	}
	s.insert({2e9, 2 * n});
	for (int i = n; i < 2 * n; i++){
		auto it = s.lower_bound({x[i - n] + l, i});
		it++, link(i, (*it).second);
	}
}
int update(int i, int y){
	auto it = s.lower_bound({x[i] + l, i + n}), it1 = it, it2 = it;
	auto it3 = s.lower_bound({x[i], i}), it4 = it3;
	it1++, it2--;
	cut(i + n, (*it1).second);
	bool f1 = 0, f2 = 0;
	if (it3 != s.begin()){
		it4--;
		if ((*it4).second >= n) f1 = 1, cut((*it4).second, i);
	}
	if (it3 != it2 && (*it2).second >= n) f2 = 1, cut((*it2).second, i + n);
	s.erase(it), s.erase(it3);
	if (f1) it3 = it4, it3++, link((*it3).second, (*it4).second);
	if (f2) it = it2, it++, link((*it).second, (*it2).second);
	x[i] = y;
	it1 = it = s.lower_bound({x[i], i}), it2 = it3 = s.lower_bound({x[i] + l, i + n});
	if (it != s.begin()){
		it1--;
		if ((*it1).second >= n) cut((*it1).second, (*it).second), link((*it1).second, i);
	}
	if (it3 != s.begin()){
		it2--;
		if (it2 != it1 && (*it2).second >= n) cut((*it2).second, (*it3).second), link((*it2).second, i + n);
	}
	s.insert({x[i], i}), s.insert({x[i] + l, i + n}); 
	link(i + n, (*it3).second);
	return split((*s.begin()).second, 2 * n);
}
int main(){}
