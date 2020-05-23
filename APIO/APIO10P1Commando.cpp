#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int MM = 1e6 + 5;
int n, l, r, q[MM]; ll s[MM], a, b, c, dp[MM];
ll get(int j, int k){return dp[j] - dp[k] + a * (s[j] * s[j] - s[k] * s[k]) + b * (s[k] - s[j]);}
int main(){
	n = re, a = re, b = re, c = re;
	for (int i = 1; i <= n; i++) s[i] = re + s[i - 1];
	for (int i = 1; i <= n; i++){
		while(l < r && get(q[l + 1], q[l]) > 2 * a * s[i] * (s[q[l + 1]] - s[q[l]])) l++;
		dp[i] = dp[q[l]] + a * (s[i] - s[q[l]]) * (s[i] - s[q[l]]) + b * (s[i] - s[q[l]]) + c;
		while(l < r && get(i, q[r]) * (s[q[r]] - s[q[r - 1]]) > get(q[r], q[r - 1]) * (s[i] - s[q[r]])) r--;
		q[++r] = i;
	}
	printf("%lld", dp[n]);
}
