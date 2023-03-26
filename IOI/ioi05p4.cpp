#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6 + 5;
int n, ans, a[MM], psa[MM]; 
bool check(int x){
	memset(psa, 0, sizeof psa);
	for (int i = 1; i <= n; i++){
		if (a[i] > i){
			if (a[i] - x <= i) psa[0]++, psa[a[i] + x - i + 1]--, psa[a[i] - x + n - i]++;
			else if (a[i] + x - n >= i) psa[0]++, psa[a[i] + x - n - i + 1]--, psa[a[i] - x - i]++;
			else psa[a[i] - i - x]++, psa[a[i] - i + x]--;
		} else {
			if (i <= a[i] + x) psa[0]++, psa[a[i] + x - i + 1]--, psa[a[i] - x - i + n]++;
			else if (a[i] - x + n <= i) psa[0]++, psa[a[i] + x + n - i + 1]--, psa[a[i] - x + 2 * n - i]++;
			else psa[a[i] - x + n - i]++, psa[a[i] + x + n - i + 1]--;
		}
	}
	for (int i = 1; i <= n; i++) psa[i] += psa[i - 1];
	for (int i = 0; i < n; i++) 
		if (psa[i] == n) return 1;
	return psa[n - 1] == n;
}
int solve(){
	int l = 0, r = n / 2;
	while(l < r){
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	ans = solve(); reverse(a + 1, a + 1 + n); ans = min(ans, solve());
	printf("%d\n", ans);
}

