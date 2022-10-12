#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f; const char sp=' ',nl='\n';
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define re read()
#define pb push_back
const int mod = 1e9 + 7, base = 131, MM = 2e5 + 5;
int n, x, p1, p2, ans, a[MM], dp[MM], dp2[MM];
vector<int> lds[MM];
int main(){
	n = re, x = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	dp2[0] = INF;
	for (int i = n; i; i--){
		if (a[i] < dp2[p2]) dp2[++p2] = a[i], lds[p2].pb(a[i]);
		else {
			int t = lower_bound(dp2, dp2 + p2, a[i], greater<int>()) - dp2;
			dp2[t] = a[i], lds[t].pb(a[i]);
		}
	}
	for (int i = 1; i <= n; i++){
		int t = lower_bound(dp2, dp2 + p2, a[i], greater<int>()) - dp2;
		lds[t].pop_back(); dp2[t] = lds[t].back();
		if (t == p2 && lds[t].empty()) p2--;
		int p;
		if (a[i] > dp[p1]) dp[++p1] = a[i], p = p1;
		else {
			t = lower_bound(dp, dp + p1, a[i]) - dp;
			dp[t] = a[i], p = t;
		}
		t = lower_bound(dp2, dp2 + p2 + 1, a[i] - x, greater<int>()) - dp2;
		ans = max(ans, p + t - 1);
	}
	pr(ans);
	return 0;
}

