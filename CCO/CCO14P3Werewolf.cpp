#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
struct edge{int a; char type;};
int N, W, M, in[210];
ll dp[210][210][2];
vector<edge> adj[210];
void add(ll &a, ll b){
	a = a + b;
	a %= MOD;
}
void dfs(int src){
	dp[src][0][0] = dp[src][1][1] = 1;
	for (auto v : adj[src]){
		dfs(v.a);
		for (int i = W; i >= 0; i--){
			ll w = 0, nw = 0;
			for (int j = 0; j <= i; j++){
				add(nw, dp[src][i - j][0] * (dp[v.a][j][0] + dp[v.a][j][1]));
				if (v.type == 'D') add(w, dp[src][i - j][1] * dp[v.a][j][1]);
				else add(w, dp[src][i - j][1] * dp[v.a][j][0]);
			}
			dp[src][i][0] = nw, dp[src][i][1] = w;
		}
	}
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, W, M);
    for (int i = 0, a, b; i < M; i++){
		char c; sc(c, a, b);
		adj[a].pb({b, c});
		in[b]++;
	}
	for (int i = 1; i <= N; i++) if (!in[i]) adj[0].pb({i, 'D'});
	dfs(0);
	pr(dp[0][W][0]); 
    return 0;
}

