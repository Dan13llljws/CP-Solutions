#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n; long long psa[405], dp[405][405];
int main(){
	n = read(); memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; i++) dp[i][i] = read(), psa[i] = dp[i][i] + psa[i - 1];
	for (int len = 2; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++)
			for (int i = l; i < r; i++)
				dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + psa[r] - psa[l - 1]);
	printf("%lld", dp[1][n] - psa[n]);
}
