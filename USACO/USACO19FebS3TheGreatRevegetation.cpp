#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, dsu[200005];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
int main(){
	//freopen("revegetate.in", "r", stdin); freopen("revegetate.out", "w", stdout);
	scanf("%d%d", &n, &m); iota(dsu, dsu + 2 * n + 1, 0);
	for (int i = 0; i < m; i++){
		char c; int a, b;
		scanf(" %c %d%d", &c, &a, &b);
		if (c == 'S') dsu[Find(a)] = Find(b), dsu[Find(a + n)] = Find(b + n);
		else dsu[Find(a)] = Find(b + n), dsu[Find(a + n)] = Find(b);
	}
	for (int i = 1; i <= n; i++)
		if (Find(i) == Find(i + n)) return 0 * puts("0");
	for (int i = 1; i <= n; i++) cnt += Find(i) == i;
	putchar('1'); for (int i = 0; i < cnt; i++) putchar('0');
}
