#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7, base = 131, MM = 1505;
int n, ans = INF, g[MM][MM], dp[MM][MM]; // first i cities visited with j at one end and i at the other
int main(){
	n = re; ms(dp, INF);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) g[i][j] = re;
	dp[1][1] = 0, dp[2][1] = dp[2][2] = g[1][2];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i - 1; j++){
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + g[i][i - 1]);
			dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + g[i][j]);
		}
	for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
	printf("%d", ans);
	return 0;
}
