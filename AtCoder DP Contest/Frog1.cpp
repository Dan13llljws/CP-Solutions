#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, dp[100005], h[100005];
int main(){
	n = read(), h[0] = read();
	for (int i = 1; i < n; i++){
		h[i] = read();
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[max(0, i - 2)] + abs(h[i] - h[max(0, i - 2)]));
	}
	printf("%d", dp[n - 1]);
}
