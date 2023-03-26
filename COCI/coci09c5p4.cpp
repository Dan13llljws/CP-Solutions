#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, k, c[105], dp[105][105][7];
int main(){
	n = re, k = re;
	for (int i = 1; i <= n; i++) c[i] = re;
	memset(dp, inf, sizeof dp);
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= k; j++)
			dp[i][i][j] = max(0, k - j - 1), dp[i][i - 1][j] = 0;
	for (int len = 1; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++){
			for (int j = k - 1; j >= 0; j--){
				if (j == k - 1) dp[l][r][k - 1] = min(dp[l][r][k - 1], dp[l + 1][r][0]);
				else dp[l][r][j] = min(dp[l][r][j], dp[l][r][j + 1] + 1);
				for (int i = l; i <= r; i++)
					if (c[l] == c[i])
						dp[l][r][j] = min(dp[l][r][j], dp[l + 1][i - 1][0] + dp[i][r][min(k - 1, j + 1)]);
			}
		}
	printf("%d\n", dp[1][n][0]);
}
