#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
ll read(){ll s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define f first
#define s second
const int mod = 1e9 + 7, base = 131, MM = 1e5 + 5;
int n, k, l[MM], r[MM]; ll ans, a[MM]; bool vis[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
	n = re, k = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	for (int i = n; i > 1; i--){
		a[i] -= a[i - 1], l[i] = i - 1, r[i] = i + 1;
		q.push({a[i], i});
	}
	a[1] = a[n + 1] = INF;
	for (int i = 1; i <= k; i++){
		pii p = q.top(); q.pop();
		while(vis[p.s]) p = q.top(), q.pop();
		ans += p.f;
		a[p.s] = a[l[p.s]] + a[r[p.s]] - a[p.s];
		vis[l[p.s]] = vis[r[p.s]] = 1;
		r[l[l[p.s]]] = l[r[r[p.s]]] = p.s;
		l[p.s] = l[l[p.s]], r[p.s] = r[r[p.s]];
		q.push({a[p.s], p.s});
	}
	printf("%lld", ans);
}
