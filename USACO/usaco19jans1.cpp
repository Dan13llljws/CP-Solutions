#include <bits/stdc++.h>
using namespace std;
int n, ans, in[100005];
int main(){
	//freopen("planting.in", "r", stdin); freopen("planting.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1, a, b; i < n; i++){
		scanf("%d%d", &a, &b);
		in[a]++, in[b]++;
	}
	for (int i = 1; i <= n; i++) ans = max(ans, in[i] + 1);
	printf("%d\n", ans);
}
