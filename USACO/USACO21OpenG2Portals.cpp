#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
struct node{int c, p[4];}a[MM];
int n, dsu[MM<<1];
int Find(int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);}
int main(){
	scanf("%d", &n);
	iota(dsu + 1, dsu + n + n + 1, 1);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i].c);
		for (int j = 0; j < 4; j++) scanf("%d", &a[i].p[j]);
		for (int j = 0; j < 4; j += 2)
			dsu[Find(a[i].p[j])] = Find(a[i].p[j ^ 1]);
	}
	sort(a, a + n, [](node x, node y){return x.c < y.c;});
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (Find(a[i].p[0]) != Find(a[i].p[2]))
			ans += a[i].c, dsu[Find(a[i].p[0])] = Find(a[i].p[2]);
	printf("%d\n", ans);
}
		

