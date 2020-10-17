#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, m, dp[1005][1005], mod = 1e9 + 7;
int main(){
	n = read(), m = read();
	dp[0][1] = 1; 
	for (int i = 1; i <= n; i++, getchar())
		for (int j = 1; j <= m; j++){
			int c = getchar();
			if (c != '#') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	printf("%d", dp[n][m]);
}
