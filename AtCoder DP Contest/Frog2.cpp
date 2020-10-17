#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
int n, k, h[100001], dp[100001];
int main(){
    n = read(), k = read(), h[0] = read();
    for (int i = 1; i < n; i++){
		h[i] = read(), dp[i] = 1e9;
		for (int j = max(0, i - k); j < i; j++)
			dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
	}
	printf("%d", dp[n - 1]);
}
