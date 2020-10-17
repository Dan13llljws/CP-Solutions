#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
typedef long long ll;
int n; ll dp[3005][3005];
int main(){
	n = read();
	for (int i = 1; i <= n; i++) dp[i][i] = read();
	for (int len = 2; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++)
			dp[l][r] = max(dp[l][l] - dp[l + 1][r], dp[r][r] - dp[l][r - 1]);
	printf("%lld", dp[1][n]);
}
