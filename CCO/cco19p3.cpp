#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int mod = 1e9 + 7, MM = 2e5 + 5;
int n, rt, a[MM], w[MM]; ll ans, mx; vector<int> adj[MM], b, sum;
int get_w(int src, int par){
	w[src] = a[src];
	for (int v : adj[src])
		if (v != par) w[src] += get_w(v, src);
	return w[src];
}
int get_c(int src, int par){
	for (int v : adj[src])
		if (v != par && w[v] > w[1] / 2) return get_c(v, src);
	return src;
}
int dfs(int src, int par, int d){
	ans += 1LL * a[src] * (a[src] - 1 + d); int ret = a[src];
	for (int v : adj[src])
		if (v != par) ret += dfs(v, src, d + a[src]);
	return ret;
}
int main(){
	n = re;
	for (int i = 1; i <= n; i++) a[i] = re;
	for (int i = 2; i <= n; i++){
		int a = re;
		adj[a].push_back(i), adj[i].push_back(a);
	} get_w(1, 1), rt = get_c(1, 1); ans = 1LL * a[rt] * (a[rt] - 1);
	for (int v : adj[rt]) b.push_back(dfs(v, rt, a[rt]));
	int l = b.size() / 2, r = b.size() - l;
	for (int mask = 0; mask < (1 << l); mask++){
		int cur = 0;
		for (int i = 0; i < l; i++)
			if (mask >> i & 1) cur += b[i];
		sum.push_back(cur);
	} sort(sum.begin(), sum.end());
	for (int mask = 0; mask < (1 << r); mask++){
		int cur = 0;
		for (int i = 0; i < r; i++)
			if (mask >> i & 1) cur += b[i + l];
		int tmp = lower_bound(sum.begin(), sum.end(), (w[1] - a[rt]) / 2 - cur) - sum.begin();
		if (tmp != l)
			mx = max(mx, 1LL * (cur + sum[tmp]) * (w[1] - a[rt] - cur - sum[tmp]));
		tmp--;
		if (tmp >= 0)
			mx = max(mx, 1LL * (cur + sum[tmp]) * (w[1] - a[rt] - cur - sum[tmp]));
	} printf("%lld\n", ans + mx);

}

