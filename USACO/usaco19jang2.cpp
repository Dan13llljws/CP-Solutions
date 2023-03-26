#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, ans, a[MM], bit[MM];
void update(int x){
	for (; x <= n; x += x & -x) bit[x]++;
}
int query(int x){
	int ret = 1;
	for (; x; x -= x & -x) ret += bit[x];
	return ret;
}
int main(){
	freopen("sleepy.in", "r", stdin); freopen("sleepy.out", "w", stdout);
	scanf("%d", &n); ans = n, a[n + 1] = 1e9;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	while(ans && a[ans] < a[ans + 1]) update(a[ans--]);
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++){
		printf("%d", ans - i - 1 + query(a[i]));
		update(a[i]); putchar(i == ans ? '\n' : ' ');
	}
}
