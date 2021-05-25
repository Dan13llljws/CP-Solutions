#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 1e4 + 5;
int n, cur, a[MM], dp[2][MM];
int add(int a, int b){
	int ret = a + b;
	return ret >= mod ? ret - mod : ret;
}
int main(){
	n = re, dp[cur ^ 1][0] = 1;
	for (int i = 1; i <= n; i++) a[i] = re;
	if (a[1] && a[1] != -1) return 0 * puts("0");
	for (int i = 2; i <= n; i++, cur ^= 1){
		memset(dp[cur], 0, sizeof dp[cur]);
		if (a[i] == -1){
			for (int j = 0; j <= n; j++){
				dp[cur][j] = add(dp[cur ^ 1][j], dp[cur ^ 1][j + 1]);
				if (j) dp[cur][j] = add(dp[cur][j], dp[cur ^ 1][j - 1]);
			} 
		} else {
			dp[cur][a[i]] = add(dp[cur ^ 1][a[i]], dp[cur ^ 1][a[i] + 1]);
			if (a[i]) dp[cur][a[i]] = add(dp[cur][a[i]], dp[cur ^ 1][a[i] - 1]);
		}
	}
	printf("%d\n", dp[cur ^ 1][0]);
}
