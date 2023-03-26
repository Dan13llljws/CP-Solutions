#include <iostream>
int x, n, ans;
int main(){
	scanf("%d%d", &x, &n);
	ans = (n + 1) * x;
	for (int i = 0, a; i < n; i++) scanf("%d", &a), ans -= a;
	printf("%d\n", ans);
}
