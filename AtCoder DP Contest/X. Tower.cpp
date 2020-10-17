#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
struct block{int w, s, v;}b[1005];
int n; long long dp[20005], ans;
bool cmp(block a, block b){return a.w + a.s < b.w + b.s;}
int main(){
	n = read();
	for (int i = 0; i < n; i++) b[i] = {read(), read(), read()};
	sort(b, b + n, cmp);
	for (block x : b)
		for (int i = x.w + x.s; i >= x.w; i--)
			dp[i] = max(dp[i], dp[i - x.w] + x.v);
	for (int i = 0; i <= 20005; i++) ans = max(ans, dp[i]);
	printf("%lld", ans);
}
