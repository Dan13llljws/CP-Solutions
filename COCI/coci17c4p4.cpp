#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 5005;
int n, m, k, t[MM], dp[MM][MM];
int main(){
	n = re, m = re, k = re;
	for (int i = 1; i <= n; i++) t[i] = re;
	for (int i = m - 1; i; i--)
		for (int j = 1; j <= n; j++)
			dp[j][i] = (!!(dp[j%n+1][i + 1] - dp[j%n+1][min(m, i + k) + 1]) ^ t[j] ^ t[j%n+1]) + dp[j][i + 1];
	for (int i = 1; i <= n; i++) printf("%d ", !(dp[i][1] - dp[i][k + 1]) ^ t[i]);
}
