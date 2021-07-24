#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, ans = 1, bit[MM]; pair<int,int> p[MM];
void upd(int x){
	for (; x <= n; x +=x & -x) bit[x]++;
}
int get(int x){
	int ret = 0;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i].first), p[i].second = i;
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++) upd(p[i].second), ans = max(ans, i - get(i));
	printf("%d\n", ans);
}
