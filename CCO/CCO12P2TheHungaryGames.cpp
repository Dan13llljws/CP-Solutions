#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define nl '\n'
#define sz(x) (int)(x.size())
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n, m; ll dist[2][20001], ans = INF, t;
vector<pii> adj1[20001], adj2[20001];
void dijkstra(int src, ll dist[], vector<pii> adj[]){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[src] = 0;
    q.push(mp(0, src));
    while(!q.empty()){
        int p = q.top().s; ll t = q.top().f; q.pop();
        if (t != dist[p]) continue;
        for (auto v : adj[p]){
            if (dist[v.s] > dist[p] + v.f){
                dist[v.s] = dist[p] + v.f;
                q.push(mp(dist[v.s], v.s));
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n >> m;
    for (int i = 0, a, b, l; i < m; i++){
        cin >> a >> b >> l;
        adj1[a].pb(mp(l, b)); adj2[b].pb(mp(l, a));
    }
    ms(dist, INF);
    dijkstra(1, dist[0], adj1); dijkstra(n, dist[1], adj2);
    t = dist[0][n];
    for (int i = 1; i <= n; i++){
        for (auto v : adj1[i]){
            ll tmp = dist[0][i] + v.f + dist[1][v.s];
            if (tmp > t) ans = min(tmp, ans);
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
    return 0;
}