#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5e4 + 5;
int n, c, ans, w[MM][32], dp[MM][32];
int main(){
	n = re, c = re;
	for (int i = 1; i <= c; i++){
		int e = re, f = re, l = re, hate = 0, love = 0;
		for (int j = 0; j < f; j++) hate |= 1 << ((re - e + n) % n);
		for (int j = 0; j < l; j++) love |= 1 << ((re - e + n) % n);
		for (int j = 0; j < 32; j++)
			if ((j & hate) || (~j & love)) w[e][j]++;
	}
	for (int mask = 0; mask < 32; mask++){
		for (int i = 0; i < 32; i++) dp[0][i] = -1e9;
		dp[0][mask] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 32; j++)
				dp[i][j] = max(dp[i - 1][(j << 1) & 31], dp[i - 1][(j << 1 | 1) & 31]) + w[i][j];
		ans = max(ans, dp[n][mask]);
	}
	printf("%d\n", ans);
}

