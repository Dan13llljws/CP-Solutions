#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, v, t[MM]; vector<int> f[MM];
int main(){
	//freopen("dishes.in", "r", stdin); freopen("dishes.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0, x; i < n; i++){
		scanf("%d", &x);
		if (x < v) return 0 * printf("%d\n", i);
		for (int j = x; j && !t[j]; j--) t[j] = x;
		int p = t[x];
		while(f[p].size() && f[p].back() < x)
			v = f[p].back(), f[p].pop_back();
		f[p].push_back(x);
	}
	printf("%d\n", n);
}
