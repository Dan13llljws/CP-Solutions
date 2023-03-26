#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define ms(x, y) memset(x, y, sizeof(x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MM = 1e6 + 5;
int n, m, P, dist[MM];
vector<vector<char>> g, ans;
vector<vector<int>> t;
vector<pii> adj[MM];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y, int k){
	if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '.' || t[x][y]) return;
	t[x][y] = k;
	for (int i = 0; i < 4; i++)
		dfs(x + dir[i][0], y + dir[i][1], k);
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	sc(n, m);
	g.resize(n, vector<char>(m));
	t.resize(n, vector<int>(m));
	ans.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sc(g[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '#' && !t[i][j])
				dfs(i, j, ++P);
	for (int j = 0; j < m; j++){
		int cur = 0, d = 0;
		for (int i = n - 1; i >= 0; i--){
			if (g[i][j] == '.') d++;
			else if (t[i][j] != cur){
				adj[cur].pb(mp(d, t[i][j]));
				cur = t[i][j];
				d = 0;
			}
			else d = 0;
		}
	}
	ms(dist, INF); dist[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(mp(0, 0));
	while(sz(q)){
		int p = q.top().s, d = q.top().f; q.pop();
		if (d > dist[p]) continue;	
		for (auto v : adj[p]){	
			if (dist[v.s] > dist[p] + v.f){
				dist[v.s] = dist[p] + v.f;
				q.push(mp(dist[v.s], v.s));
			}
		}
	}
	for (int j = 0; j < m; j++)
		for (int i = n - 1; i >= 0; i--)
			if (g[i][j] == '#')
				ans[i + dist[t[i][j]]][j] = '#';
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			pr(ans[i][j] == '#' ? '#' : '.');
		pr(nl);
	}
	return 0;
}
