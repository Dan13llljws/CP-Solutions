#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
struct E{int a, b, i, w;}e[MM];
int n, q, dsu[MM], sz[MM], ans[MM];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
void unite(int x, int y){x = Find(x), y = Find(y);sz[y] += sz[x], dsu[x] = y;}
int main(){
	//freopen("mootube.in", "r", stdin); freopen("mootube.out", "w", stdout);
	scanf("%d%d", &n, &q); iota(dsu, dsu + n + 1, 0), sz[n] = 1;
	for (int i = 1; i < n; i++) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w), sz[i] = 1;
	for (int i = 0; i < q; i++) scanf("%d%d", &e[i+n].w, &e[i+n].a), e[i+n].i = i;
	sort(e + 1, e + n + q, [&](E a, E b){return a.w == b.w ? a.b > b.b : a.w > b.w;});
	for (int i = 1; i < n + q; i++){
		if (e[i].b) unite(e[i].a, e[i].b);
		else ans[e[i].i] = sz[Find(e[i].a)];
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i] - 1);
}
	
