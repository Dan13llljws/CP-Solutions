#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
int n, m, k, p[505], b[505], dp[505];
int main(){
	n = re, m = re, k = re;
	for (int i = 0; i < n; i++) p[i] = re;
	for (int i = 0; i <= m; i++) b[i] = re;
	for (int i = 0; i < n; i++)
		for (int j = k; j >= 0; j--)
			for (int x = 0; x <= j; x++)
				dp[j] = max(dp[j], dp[j - x] + b[p[i] + x]);
	printf("%d", dp[k]);
}

