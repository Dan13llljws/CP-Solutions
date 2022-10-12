#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int N, L, cur, pre = 1, a[105]; ll dp[2][105][1005][4];
int main(){
	N = re, L = re;
	if (N == 1) return 0 * puts("1");
	for (int i = 1; i <= N; i++) a[i] = re;
	sort(a + 1, a + N + 1);
	dp[1][0][0][0] = 1;
	for (int i = 0; i < N; i++, swap(pre, cur)){
		memset(dp[cur], 0, sizeof dp[cur]);
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= L; k++)
				for (int i1 = 0; i1 < 3; i1++){
					int nk = k + (2 * j - i1) * (a[i + 1] - a[i]); ll tdp = dp[pre][j][k][i1];
					if (nk > L || !dp[pre][j][k][i1]) continue;
					dp[cur][j + 1][nk][i1] = (dp[cur][j + 1][nk][i1] + (j + 1 - i1) * tdp) % mod;
					dp[cur][j + 1][nk][i1 + 1] = (dp[cur][j + 1][nk][i1 + 1] + (i1 - 2) * tdp) % mod;
					if (j > 1) dp[cur][j - 1][nk][i1] = (dp[cur][j - 1][nk][i1] + tdp * (j - 1)) % mod;
					if (j) dp[cur][j][nk][i1] = (dp[cur][j][nk][i1] + tdp * (j * 2 - i1)) % mod;
					if (j) dp[cur][j][nk][i1 + 1] = (dp[cur][j][nk][i1 + 1] + tdp * (i1 - 2)) % mod;
				} 
	}
	ll ans = 0;
	for (int i = 0; i <= L; i++) ans = (ans + dp[pre	][1][i][2]) % mod;
	printf("%lld\n", ans);
}

