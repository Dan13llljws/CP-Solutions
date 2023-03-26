#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
const int MM = 1e5 + 5;
int N, K, cnt[MM], q[MM]; ll ans = LLINF, dp[MM]; pii p[MM];
ll sqr(ll a){return a * a;}
double get(int j, int k){return (dp[j] - dp[k] + sqr(p[j + 1].f) - sqr(p[k + 1].f)) / (2.0 * (p[j + 1].f - p[k + 1].f));}
bool check(ll C){
	int l = 0, r = 0;
	for (int i = 1; i <= N; i++){
		while(l < r && get(q[l + 1], q[l]) < p[i].s + 1) l++;
		dp[i] = dp[q[l]] + sqr(p[i].s - p[q[l] + 1].f + 1) + C;
		cnt[i] = cnt[q[l]] + 1;
		if (i == N) break;
		if (p[i].s >= p[i + 1].f) dp[i] -= sqr(p[i].s - p[i + 1].f + 1);
		while(l < r && get(q[r], q[r - 1]) > get(i, q[r])) r--;
		q[++r] = i;
	}
	return cnt[N] <= K;
}
long long take_photos(int n, int m, int k, int* r, int* c){
	for (int i = 0; i < n; i++){
		if (r[i] > c[i]) swap(r[i], c[i]);
		p[i + 1] = {r[i], c[i]};
	}
	sort(p + 1, p + 1 + n, [](pii a, pii b){return a.s == b.s ? a.f > b.f : a.s < b.s;});
	m = 0;
	for (int i = 1; i <= n; i++){
		while(m && p[m].f >= p[i].f) m--;
		p[++m] = p[i];
	}
	N = m, K = k;
	ll L = 0, R = 1e18;
	while(L < R){
		ll mid = (L + R) >> 1;
		if (check(mid)) R = mid, ans = dp[N];
		else L = mid + 1;
	}
	return ans - L * K;
}
int main(){	
}
