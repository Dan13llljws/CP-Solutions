#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Edge {
  int to, rev;
  ll c, oc;
  Edge(int to, int rev, ll c, ll oc): to(to), rev(rev), c(c), oc(oc) {}
  ll flow() { return max(oc - c, 0LL); } // if you need flows
};
struct Dinic {
  vector<vector<Edge>> adj;
  vector<int> lvl, ptr, q;
  ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < (int)adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
  Dinic(int n): adj(n), lvl(n), ptr(n), q(n) {}
  void addEdge(int a, int b, ll c, ll rcap = 0){
    adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	} 
	ll maxFlow(int s, int t) {
		ll flow = 0; q[0] = s;
    for (int L = 0; L < 31; L++) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vector<int>(q.size());
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  Dinic g(n + 1);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    g.addEdge(a, b, 1);
  }
  cout << g.maxFlow(1, n) << '\n';
  for (Edge e : g.adj[1]){
    if (!e.flow()) continue;
    vector<int> p = {1, e.to};
    for (int i = e.to; i != n; ){
      for (Edge &f : g.adj[i])
        if (f.flow()){
          f.oc = f.c, p.push_back(i = f.to);
          break;
        }
    }
    cout << p.size() << '\n';
    for (int x : p) cout << x << ' ';
    cout << '\n';
  }
}
