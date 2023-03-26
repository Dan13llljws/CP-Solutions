#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int f, v, g, dp[105][105], ans[105];
int main(){
	f = re, v = re; memset(dp, -0x3f, sizeof dp); memset(dp[0], 0, sizeof dp[0]);
	for (int i = 1; i <= f; i++)
		for (int j = 1; j <= v; j++)
			g = re, dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + g);
	printf("%d\n", dp[f][v]);
	for (int i = f, j = v; i; ans[i--] = j--)
		while(dp[i][j] == dp[i][j - 1]) j--;
	for (int i = 1; i <= f; i++) printf("%d ", ans[i]);
}

