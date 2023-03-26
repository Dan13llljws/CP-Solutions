#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7;
int n, l, r, k, a[105], ans = INF, dp[105][10005];
int main(){
	n = re, l = re, r = re, k = re; ms(dp, inf); dp[0][0] = 0;
	for (int i = 1; i <= n; i++) a[i] = re;
	for (int i = 1; i <= n; i++)
		for (int j = min(r - l + 1, i); j; j--)
			for (int x = k; x >= abs(l + j - 1 - i); x--)
				dp[j][x] = min(dp[j][x], dp[j - 1][x - abs(l + j - 1 - i)] + a[i]);
	for (int i = 0; i <= k; i++) ans = min(ans, dp[r - l + 1][i]);
	printf("%d", ans);
}
