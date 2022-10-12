#include <bits/stdc++.h>
using namespace std;
void build(vector<vector<int>> b){}
int construct(vector<vector<int>> p){
	int n = p.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (p[i][j] == 3) return 0;
	vector<int> vis(n), dsu(n); vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) dsu[i] = i;
	function<int(int)> Find = [&](int x){return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);};
	for (int i = 0; i < n; i++){
		if (vis[i]) continue;
		vector<int> tree;
		tree.push_back(i), vis[i] = 1;
		for (int f = 0; f < (int)tree.size(); f++){
			int src = tree[f];
			for (int j = 0; j < n; j++)
				if (p[src][j] == 1 && !vis[j])
					vis[j] = 1, tree.push_back(j);
		}
		int t = tree.size();
		for (int j = 0; j < t; j++)
			for (int k = 0; k < t; k++)
				if (j != k && p[tree[j]][tree[k]] != 1) return 0;
		for (int j = 0; j < t - 1; j++)
			ans[tree[j]][tree[j + 1]] = 1, dsu[Find(tree[j])] = Find(tree[j + 1]);
	}
	fill(vis.begin(), vis.end(), 0);
	for (int i = 0; i < n; i++){
		if (vis[i] || i != Find(i)) continue;
		vector<int> cycle;
		cycle.push_back(i), vis[i] = 1;
		for (int f = 0; f < (int)cycle.size(); f++){
			int src = cycle[f];
			for (int j = 0; j < n; j++)
				if (j == Find(j) && p[src][j] == 2 && !vis[j])
					cycle.push_back(j), vis[j] = 1;
		}
		int c = cycle.size();
		if (c == 2) return 0;
		for (int j = 0; j < c; j++)
			for (int k = 0; k < c; k++)
				if (j != k && p[cycle[j]][cycle[k]] != 2) return 0;
		for (int j = 0; j < c; j++)
			ans[cycle[j]][cycle[(j+1)%c]] = 1, dsu[Find(cycle[j])] = Find(cycle[(j+1)%c]);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && p[i][j] && Find(i) != Find(j)) return 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j) ans[i][j] = 0;
			else if (ans[i][j]) ans[j][i] = 1;
	build(ans);
	return 1;
}
int main(){}

