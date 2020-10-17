#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int mod = 1e9 + 7;
int n, dp[1<<21]; bool g[21][21];
int main(){
	n = read(); dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) g[i][j] = read();
	for (int mask = 1; mask < 1 << n; mask++)
		for (int i = 0; i < n; i++)
			if (g[__builtin_popcount(mask) - 1][i] && mask >> i & 1)
				dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % mod;
	printf("%d", dp[(1<<n)-1]);
}
