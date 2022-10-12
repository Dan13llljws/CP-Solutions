#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 5;
int n, q, lst[MM], ans[MM]; vector<int> adj[MM], vis[MM]; unordered_map<int,int> id[MM]; 
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int k; scanf("%d", &k), adj[i].resize(k), vis[i].resize(k);
		for (int j = 0; j < k; j++) scanf("%d", &adj[i][j]), id[i][adj[i][j]] = j;
	}
	for (int i = 1; i <= n; i++){
		for (int i1 = 0; i1 < (int)adj[i].size(); i1++){
			int v = adj[i][i1];
			if (vis[i][i1]) continue;
			vector<int> cycle = {i, v};
			int pre = -1, cur = i, nxt = v;
			vis[i][i1] = 1;
			while(1){
				pre = cur, cur = nxt, nxt = id[cur][pre] - 1;
				if (nxt < 0) nxt += adj[cur].size();
				vis[cur][nxt] = 1, nxt = adj[cur][nxt], cycle.push_back(nxt);
				if (cur == cycle[0] && nxt == cycle[1]) break;
			} cycle.pop_back(), cycle.pop_back(); int tmp = cycle.size();
			for (int j = 0, k = 0; j < 2 * tmp; j++, k++){
				if (k == tmp) k = 0;
				if (lst[cycle[k]] != -1) ans[cycle[k]] = max(ans[cycle[k]], j - lst[cycle[k]]);
				lst[cycle[k]] = j;
			}
		}
	} scanf("%d", &q);
	while(q--){
		int x; scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
}

