#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, W, ans, tot, dp[100005];
int main(){
	n = read(), W = read();
	memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	for (int i = 0; i < n; i++){
		int w = read(), v = read(); tot += v;
		for (int j = tot; j >= v; j--)
			dp[j] = min(dp[j], dp[j - v] + w);
	}
	for (int i = tot; i >= 0; i--)
		if (dp[i] <= W) return 0 * printf("%d", i);
}
	
