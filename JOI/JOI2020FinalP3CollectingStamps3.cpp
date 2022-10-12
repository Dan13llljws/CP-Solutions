#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, ans, x[205], t[205], dp[205][205][205][2];
int main(){
	n = re, x[n + 1] = re; memset(dp, inf, sizeof dp); dp[n + 1][0][0][0] = 0;
	for (int i = 1; i <= n; i++) x[i] = re;
	for (int i = 1; i <= n; i++) t[i] = re;
	for (int i = n + 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			for (int k = 0; k <= n + 1 - i + j; k++){
				int m1 = min(dp[i][j][k][0] + x[i] - x[i - 1], dp[i][j][k][1] + x[n + 1] - x[i - 1] + x[j]);
				int m2 = min(dp[i][j][k][0] + x[n + 1] - x[i] + x[j + 1], dp[i][j][k][1] + x[j + 1] - x[j]);
				dp[i - 1][j][k][0] = min(dp[i - 1][j][k][0], m1);
				dp[i][j + 1][k][1] = min(dp[i][j + 1][k][1], m2);
				if (m1 <= t[i - 1]) dp[i - 1][j][k + 1][0] = min(dp[i - 1][j][k + 1][0], m1);
				if (m2 <= t[j + 1]) dp[i][j + 1][k + 1][1] = min(dp[i][j + 1][k + 1][1], m2);
			}
	for (int i = n + 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			for (int k = 0; k <= n + 1 - i + j; k++)
				if (dp[i][j][k][0] < 1e9 || dp[i][j][k][1] < 1e9) ans = max(ans, k);
	printf("%d\n", ans);
}

