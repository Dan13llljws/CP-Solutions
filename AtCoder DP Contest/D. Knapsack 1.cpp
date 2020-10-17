#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
long long n, W, dp[100000];
int main(){
	 n = read(), W = read();
	 for (int i = 0; i < n; i++){
		 int w = read(), v = read();
		 for (int j = W; j >= w; j--)
			dp[j] = max(dp[j], dp[j - w] + v);
	}
	printf("%lld", dp[W]);
}
