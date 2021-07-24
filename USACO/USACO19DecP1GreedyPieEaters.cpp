#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, m, c[305][305], dp[305][305], mx[305][305][305];
int main(){
	n = re, m = re;
	for (int i = 0, a; i < m; i++) a = re, c[re][re] = a;
	for (int i = 1; i <= n; i++)
		for (int j = i; j; j--)
			for (int k = i; k <= n; k++){
				mx[i][j][k] = c[j][k];
				if (j < i) mx[i][j][k] = max(mx[i][j][k], mx[i][j + 1][k]);
				if (k > i) mx[i][j][k] = max(mx[i][j][k], mx[i][j][k - 1]);
			}
	for (int len = 1; len <= n; len++)
		for (int l = 1, r = len; r <= n; l++, r++)
			for (int i = l; i <= r; i++){
				dp[l][r] = max(dp[l][r], mx[i][l][r] + dp[l][i - 1] + dp[i + 1][r]);
				dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][r]);
			}
	printf("%d\n", dp[1][n]);
}

