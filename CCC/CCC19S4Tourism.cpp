#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7, MM = 1e6 + 5;
int n, k, a[MM], day[MM], q[MM]; ll dp[MM], ans;
void do_dp(){
	q[0] = 1;
	for (int i = 1, j = 0, l = 0, r = 0; i <= n; i++){
		if (j < i - k) j = i - k;
		while(l <= r && q[l] <= j) l++;
		int x = a[q[l]], y = q[l] == j + 1 ? a[q[l + 1]] : a[q[l]];
		while(day[j] == day[j + 1] && dp[j] + x <= dp[j + 1] + y)
			j++, x = a[q[l]], y = q[l] == j + 1 ? a[q[l + 1]] : a[q[l]];
		while(l <= r && q[l] <= j) l++;
		while(l <= r && a[i] >= a[q[r]]) r--;
		q[++r] = i;
		dp[i] = dp[j] + a[q[l]];
	}
	ans = max(ans, dp[n]);
}
int main(){
	n = re, k = re;
	for (int i = 1; i <= n; i++) a[i] = re, day[i] = (i + k - 1) / k;
	do_dp(); reverse(a + 1, a + 1 + n); ms(dp, 0); do_dp();
	printf("%lld", ans);
}
