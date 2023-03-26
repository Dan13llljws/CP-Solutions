#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f,INF=0x3f3f3f3f; const ll LLINF=0x3f3f3f3f3f3f3f3f;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define lc i << 1
#define rc i << 1 | 1
const int mod = 1e9 + 7, MM = 1e5 + 5;
struct line{
	int m; ll b = LLINF;
	ll f(int x){return 1LL * m * x + b;}
}seg[4000005];
int n, h[MM]; ll w[MM], dp;
void update(line cur, int i, int l, int r){
	int m = l + r >> 1;
	bool lft = cur.f(l) < seg[i].f(l), mid = cur.f(m) < seg[i].f(m);
	if (mid) swap(cur, seg[i]);
	if (l == r) return;
	if (lft != mid) update(cur, lc, l, m);
	else update(cur, rc, m + 1, r);
}
ll get(int x, int i, int l, int r){
	if (l == r) return seg[i].f(x);
	int m = l + r >> 1;
	if (x < m) return min(seg[i].f(x), get(x, lc, l, m));
	return min(seg[i].f(x), get(x, rc, m + 1, r));
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) h[i] = re; 
	for (int i = 1; i <= n; i++) w[i] = w[i - 1] + re;
	update({-2 * h[1], -w[1] + 1LL * h[1] * h[1]}, 1, 0, 2e6);
	for (int i = 2; i <= n; i++){
		dp = get(h[i], 1, 0, 2e6) + w[i - 1] + 1LL * h[i] * h[i];
		update({-2 * h[i], dp - w[i] + 1LL * h[i] * h[i]}, 1, 0, 2e6);
	}
	printf("%lld\n", dp);
}
