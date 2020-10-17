#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, k, cur, dp[2][MM];
int main(){
	n = read(), k = read(); dp[1][0] = 1;
	for (int i = 0; i < n; i++, cur ^= 1){
		int a = read();
		for (int j = 0; j <= k; j++){
			int r = min(j + a, k) + 1;
			dp[cur][j] = (dp[cur][j] + dp[cur ^ 1][j]) % mod;
			dp[cur][r] = (dp[cur][r] - dp[cur ^ 1][j] + mod) % mod;
			dp[cur ^ 1][j] = 0;
		}
		for (int j = 1; j <= k; j++) dp[cur][j] = (dp[cur][j] + dp[cur][j - 1]) % mod;
	}
	printf("%d", dp[cur ^ 1][k]);
}
