#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e4 + 5;
int n, e, a, b, mx, cur, ans, dp[2][MM];
int main(){
	n = re, e = re; iota(dp[1], dp[1] + e, 0);
	for (int i = 1; i < n; i++, cur ^= 1){
		memset(dp[cur], 0, sizeof dp[cur]);
		a = re, b = re, mx = *max_element(dp[cur ^ 1], dp[cur ^ 1] + a);
		for (int j = 0; j < b; j++)
			dp[cur][j] = max(mx + j, dp[cur ^ 1][a + j]);
		for (int j = b; j < a + b; j++)
			dp[cur][j] = max(dp[cur][j], dp[cur ^ 1][j - b] + b);
		for (int j = a + b; j <= 2e4; j++)
			dp[cur][j] = max(dp[cur][j], dp[cur ^ 1][j]);
	}
	printf("%d\n", *max_element(dp[cur ^ 1], dp[cur ^ 1] + MM)); 
}

