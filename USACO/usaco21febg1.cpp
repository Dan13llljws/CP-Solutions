#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
int n, mx, f[MM], g[MM]; long long ans;
int main(){
	scanf("%d", &n), g[0] = 1;
	for (int i = 0, x; i < n; i++) scanf("%d", &x), f[x]++, mx = max(mx, x);
	for (int i = 1; i <= 1e6; i++) f[i] += f[i - 1];
	for (int i = 1; i <= mx; i++){
		for (int j = i; j <= mx; j += i)
			g[j / i] = f[min(mx, j + i - 1)] - f[j - 1];
		vector<int> odd;
		for (int j = 1; j * i <= mx; j++)
			if (g[j] & 1) odd.push_back(j);
		if (((int)odd.size() == 1 && odd[0] == 1) || ((int)odd.size() == 2 && odd[0] == odd[1] - 1)) ans += g[odd.back()];
	}
	printf("%lld\n", ans);
}
