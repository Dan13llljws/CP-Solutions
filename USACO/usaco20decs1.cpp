#include <bits/stdc++.h>
using namespace std;
int n, ans, in[100005];
int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int a, b; scanf("%d%d", &a, &b);
		in[a]++, in[b]++;
	}
	for (int i = 1; i <= n; i++) ans += ceil(log2(in[i] + (i == 1)));
	printf("%d\n", ans + n - 1);
}
