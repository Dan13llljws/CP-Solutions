#include <bits/stdc++.h>
using namespace std;
int read(){int s=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+ch-'0',ch=getchar();}return s*f;}
#define re read()
typedef pair<int, int> pii;
const int MM = 2e5 + 5;
int M, w[MM], ans = 1e9; bool vis[MM]; vector<pii> adj[MM]; map<int, int> cnt, tmp;
void get_weight(int src, int par){
	w[src] = 1;
	for (auto v : adj[src]){
		if (v.second == par || vis[v.second]) continue;
		get_weight(v.second, src);
		w[src] += w[v.second];
	}
}
int get_cent(int src, int par, int wt){
	for (auto v : adj[src]){
		if (v.second == par || vis[v.second]) continue;
		if (w[v.second] * 2 > wt) return get_cent(v.second, src, wt);
	}
	return  src;
}
void proc_subtree(int src, int par, int d, int dep){
    if (d > M) return;
	if (d == M) ans = min(ans, dep);
	if (!tmp.count(d)) tmp[d] = dep;
	else tmp[d] = min(tmp[d], dep);
	if (cnt.count(M - d)) ans = min(ans, cnt[M - d] + dep);
	for (auto v : adj[src]){
		if (v.second == par || vis[v.second]) continue;
		proc_subtree(v.second, src, d + v.first, dep + 1);
	}
}
void get_ans(int src){
	cnt.clear(); 
	for (auto v : adj[src]){
		if (vis[v.second]) continue;
		tmp.clear();
		proc_subtree(v.second, src, v.first, 1);
		for (auto m : tmp){
			if (!cnt.count(m.first)) cnt[m.first] = m.second;
			else cnt[m.first] = min(cnt[m.first], m.second);
		}
	}
}
void decomp(int src){
	vis[src] = 1;
	get_ans(src);
	for (auto v : adj[src]){
		if (vis[v.second]) continue;
		get_weight(v.second, src);
		decomp(get_cent(v.second, src, w[v.second]));
	}
}
int best_path(int N, int K, int H[][2], int L[]){
	M = K;
	for (int i = 0; i < N - 1; i++){
		int a = H[i][0], b = H[i][1], c = L[i];
		adj[a].push_back({c, b}); adj[b].push_back({c, a});
	}
	get_weight(1, 1);
	decomp(get_cent(1, 1, N));
	return ans == 1e9 ? -1 : ans;
}
int main(){
	int n = re; M = re;
	for (int i = 1; i < n; i++){
		int a = re, b = re, c = re;
		adj[a].push_back({c, b}), adj[b].push_back({c, a});
	}
	get_weight(0, 0);
	decomp(get_cent(0, 0, n));
	printf("%d\n", ans == 1e9 ? -1 : ans);
}
