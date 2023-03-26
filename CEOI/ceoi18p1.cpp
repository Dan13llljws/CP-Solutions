#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
struct item{int c, f, v;}a[4005];
int n, m, sum; ll ans, dp[100005];
bool cmp(item b, item c){return b.f == c.f ? b.v < c.v : b.f > c.f;}
int main(){
	n = re; 
	for (int i = 1; i <= n; i++) a[i] = {re, re, -re};
	m = re;
	for (int i = n + 1; i <= n + m; i++) a[i] = {re, re, re};
	sort(a + 1, a + n + m + 1, cmp);
	memset(dp, -0x3f, sizeof dp); dp[0] = 0;
	for (int i = 1; i <= n + m; i++){
		if (a[i].v < 0){
			sum += a[i].c;
			for (int j = sum; j >= a[i].c; j--)
				dp[j] = max(dp[j], dp[j - a[i].c] + a[i].v);
		} else {
			for (int j = 0; j <= sum - a[i].c; j++)
				dp[j] = max(dp[j], dp[j + a[i].c] + a[i].v);
		}
	}
	for (int i = 0; i <= sum; i++) ans = max(ans, dp[i]);
	printf("%lld", ans);
}

