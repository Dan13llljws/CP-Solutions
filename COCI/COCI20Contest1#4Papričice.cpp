#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
const int MM = 2e5 + 5;
int n, t, ans = 1e9, w[MM], in[MM], out[MM]; vector<int> adj[MM]; multiset<int> all, anc;
int dfs(int src, int par){
	w[src] = 1, in[src] = ++t;
	for (int v : adj[src])
		if (v != par) w[src] += dfs(v, src);
	out[src] = t;
	return w[src];
}
void get_ans(int a, int b, int c){ans = min(ans, max({a, b, c}) - min({a, b, c}));}
void dfs1(int src, int par){
	if (src != 1){
		if (!all.empty()){
			auto it = all.lower_bound((n - w[src]) / 2);
			if (it != all.end()) get_ans(w[src], n - w[src] - *it, *it);
			it--, get_ans(w[src], n - w[src] - *it, *it);
		}
		if (!anc.empty()){
			auto it = anc.lower_bound((n - w[src]) / 2 + w[src]);
			if (it != anc.end()) get_ans(w[src], n - *it, *it - w[src]);
			it--, get_ans(w[src], n - *it, *it - w[src]);
		}
		anc.insert(w[src]);
	}
	for (int v : adj[src])
		if (v != par) dfs1(v, src);
	if (src != 1) anc.erase(anc.lower_bound(w[src])), all.insert(w[src]);
}
int main(){
	n = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0), dfs1(1, 0);
	printf("%d\n", ans);
}
