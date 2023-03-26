#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, K, cnt[MM], q[MM]; double dp[MM];
double get(int j, int k){return (dp[j] - dp[k] - 1.0 * j / (n - j) + 1.0 * k / (n - k)) / (1.0 / (n - k) - 1.0 / (n - j));}
bool check(double mid){
	int l = 0, r = 0;
	for (int i = 1; i <= n; i++){
		while(l < r && get(q[l + 1], q[l]) < 1.0 * i) l++;
		dp[i] = dp[q[l]] + 1.0 * (i - q[l]) / (n - q[l]) - mid;
		cnt[i] = cnt[q[l]] + 1;
		while(l < r && get(q[r], q[r - 1]) > get(i, q[r])) r--;
		q[++r] = i;
	}
	return cnt[n] > K;
}
int main(){
	scanf("%d%d", &n, &K);	
	double l = 0, r = 1.0;
	while(r - l > 1e-12){
		double mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.10f", dp[n] + l * K);
}
