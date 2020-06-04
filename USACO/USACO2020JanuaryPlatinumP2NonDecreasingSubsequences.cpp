#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 5e4 + 5;
struct query{int l, r, id;};
int n, k, q, a[MM], dp[MM][21][21], ans[4*MM];
void go(int l, int r, vector<query> &que){
	if (!que.size()) return;
	if (l == r){for (query x : que) ans[x.id] = 2; return;}
	int mid = l + r >> 1;
	for (int i = l; i <= r; i++) ms(dp[i], 0);
	dp[mid][a[mid]][a[mid]] = dp[mid + 1][a[mid + 1]][a[mid + 1]] = 1;
	for (int i = mid - 1; i >= l; i--){
		for (int x = 1; x <= k; x++)
			for (int y = 1; y <= k; y++)
				dp[i][x][y] = dp[i + 1][x][y];
		dp[i][a[i]][a[i]]++;
		for (int x = a[i]; x <= k; x++)
			for (int y = a[i]; y <= k; y++)
				dp[i][a[i]][x] = (dp[i][a[i]][x] + dp[i + 1][y][x]) % mod;
	}
	for (int i = mid - 1; i >= l; i--)
		for (int x = 1; x <= k; x++)
			for (int y = 1; y < x; y++)
				dp[i][x][x] = (dp[i][x][x] + dp[i][y][x]) % mod;
	for (int i = mid + 2; i <= r; i++){
		for (int x = 1; x <= k; x++)
			for (int y = 1; y <= k; y++)
				dp[i][x][y] = dp[i - 1][x][y];
		dp[i][a[i]][a[i]]++;
		for (int x = 1; x <= a[i]; x++)
			for (int y = 1; y <= a[i]; y++)
				dp[i][x][a[i]] = (dp[i][x][a[i]] + dp[i - 1][x][y]) % mod;
	}
	for (int i = mid + 2; i <= r; i++)
		for (int x = 1; x <= k; x++)
			for (int y = x + 1; y <= k; y++)
				dp[i][x][x] = (dp[i][x][x] + dp[i][x][y]) % mod;
	vector<query> lq, rq;
	for (int i = l; i <= mid; i++) dp[i][0][0] = 1;
	for (int i = mid + 1; i <= r; i++) dp[i][k + 1][k + 1] = 1;
	for (query x : que){
		if (x.l > mid) rq.pb(x);
		else if (x.r <= mid) lq.pb(x);
		else {
			for (int i = 0; i <= k; i++)
				for (int j = i; j <= k + 1; j++)
					ans[x.id] = (ans[x.id] + 1LL * dp[x.l][i][i] * dp[x.r][j][j] % mod) % mod;
		}
	}
	go(l, mid, lq), go(mid + 1, r, rq);
}
int main(){
	n = re, k = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	q = re;
	vector<query> que(q);
	for (int i = 0; i < q; i++) que[i] = {re, re, i};
	go(1, n, que);
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}

