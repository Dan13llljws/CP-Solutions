#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, ans, a[205], dp[205][205];
int main(){
	n = re;
	for (int i = 1; i <= n; i++) dp[i + n][i + n] = dp[i][i] = re & 1;
	for (int len = 2; len <= n; len++)
		for (int l = 1, r = len; r <= 2 * n; l++, r++)
			dp[l][r] = max(dp[l][l] - dp[l + 1][r], dp[r][r] - dp[l][r - 1]);
	for (int i = 1; i <= n; i++)
		if (dp[i][i] - dp[i + 1][i + n - 1] > 0) ans++;
	printf("%d", ans);
	return 0;
}
