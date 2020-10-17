#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
const int MM = 2e5 + 5;
int n, h[MM], q[MM], l, r; ll c, dp[MM];
ll get(int j, int k){return dp[j] + 1LL * h[j] * h[j] - dp[k] - 1LL * h[k] * h[k];}
int main(){
	n = read(), c = read(), h[1] = read(), q[0] = 1;
	for (int i = 2; i <= n; i++){
	    h[i] = read();
		while(l < r && get(q[l + 1], q[l]) < 2LL * h[i] * (h[q[l + 1]] - h[q[l]])) l++;
		dp[i] = dp[q[l]] + 1LL * h[i] * h[i] + 1LL * h[q[l]] * h[q[l]] - 2LL * h[i] * h[q[l]] + c;
		while(l < r && get(i, q[r]) * (h[q[r]] - h[q[r - 1]]) < get(q[r], q[r - 1]) * (h[i] - h[q[r]])) r--;
		q[++r] = i;
	}
	printf("%lld", dp[n]);
}
