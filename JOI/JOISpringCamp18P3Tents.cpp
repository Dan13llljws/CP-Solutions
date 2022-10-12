#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7;
int h, w; ll dp[3005][3005];
int main(){
	scanf("%d%d", &h, &w);
	dp[0][0] = 1;
	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++){
			if (!i || !j){dp[i][j] = 1; continue;}
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 4 * j) % mod;
			if (j >= 2) dp[i][j] = (dp[i][j] + dp[i - 1][j - 2] * (j * (j - 1) / 2 % mod)) % mod;
			if (i >= 2) dp[i][j] = (dp[i][j] + dp[i - 2][j - 1] * (i - 1) * j) % mod;
		}
	printf("%lld\n", (dp[h][w] - 1 + mod) % mod);
}
