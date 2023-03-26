#include <bits/stdc++.h>
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int d, n, w, dp[5300];
int main(){
	d = re, n = re; memset(dp, 0x3f, sizeof dp); dp[0] = 0;
	for (int i = 0; i < n; i++){
		w = re;
		for (int j = w; j <= d; j++)
			dp[j] = std::min(dp[j], dp[j - w] + 1);
	}
	if (dp[d] == 0x3f3f3f3f) puts("Roberta acknowledges defeat.");
	else printf("Roberta wins in %d strokes.\n", dp[d]);
}
