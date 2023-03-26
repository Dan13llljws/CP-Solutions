#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, a[100005], ans;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	int l = 0, r = n - 1;
	while(l < r){
		if (a[l] + a[r] > m) r--;
		else ans = (ans + r - l) % mod, l++;
	}
	printf("%d", ans);
}
