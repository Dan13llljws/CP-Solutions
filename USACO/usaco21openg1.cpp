#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 5;
int n, tot, a[MM], bit[MM], p[MM]; long long ans;
void upd(int x, int v){
	for (;x <= n; x += x & -x) bit[x] += v;
}
int get(int x){
	int ret = 0;
	for(; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		ans += get(i);
		if (p[a[i]]) ans -= get(p[a[i]]), upd(p[a[i]], -1);
		upd(i, 1), p[a[i]] = i;
	} printf("%lld\n", ans);
}
		
