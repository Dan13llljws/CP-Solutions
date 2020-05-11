#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
const int mod = 1e9 + 7, base = 131, MM = 3e5 + 5;
int N, T, a[501], dp[MM], tot, ans[501];
int main(){
	T = re, N = re; ms(dp, -1); ms(ans, -1); dp[0] = 0;
	for (int i = 1; i <= N; i++){
		a[i] = re, tot += a[i];
		for (int j = min(tot, T); j >= a[i]; j--)
			if (dp[j - a[i]] != -1){dp[j] = i; break;}
	}
	for (int i = 1; i <= tot; i++){
		if (i <= T && tot - i <= T){
			int j = i;
			while(j) ans[dp[j]] = j - a[dp[j]], j -= a[dp[j]];
			int tmp = 0;
			for (j = 1; j <= N; j++){
				if (ans[j] != -1) printf("%d ", ans[j]);
				else printf("%d ", tmp), tmp += a[j];
			}
			return 0;
		}
	}
	return 0;
}

