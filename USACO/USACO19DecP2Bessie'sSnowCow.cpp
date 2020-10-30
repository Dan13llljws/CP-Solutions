#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
#define ms(x, y) memset(x, y, sizeof(x))
#define af(x) x.begin(), x.end()
const int mod = 1e9 + 7, MM = 1e5 + 5;
int n, q, t, in[MM], out[MM]; ll bit[2][MM]; vector<int> adj[MM]; set<pii> s[MM];
void add(int i, int x, ll v){
	for(; x <= n; x += x & -x) bit[i][x] += v;
}
void range_add(int l, int r, ll v){
	add(0, l, v), add(0, r + 1, -v);
	add(1, l, -v * (l - 1)), add(1, r + 1, v * r);
}
ll sum(int i, int x){
	ll ret = 0;
	for(; x; x -= x & -x) ret += bit[i][x];
	return ret;
}
ll get(int l, int r){
	return sum(0, r) * r + sum(1, r) - sum(0, l - 1) * (l - 1) - sum(1, l - 1);
}
void dfs(int src, int par){
	in[src] = ++t;
	for (int v : adj[src])
		if (v != par) dfs(v, src);
	out[src] = t;
}
int main(){
	n = re, q = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	dfs(1, 0);
	while(q--){
		int tp = re;
		if (tp == 1){
			int x = re, c = re; 
			auto it = s[c].lower_bound({in[x], 0});
			if (it != s[c].end() && (*it).second <= in[x]) continue;
			while(it != s[c].end() && (*it).first <= out[x])
				range_add((*it).second, (*it).first, -1), s[c].erase(it++);
			range_add(in[x], out[x], 1);
			s[c].insert({out[x], in[x]});
		} else {
			int x = re;
			printf("%lld\n", get(in[x], out[x]));
		}
	}
}

