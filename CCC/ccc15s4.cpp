#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define sz(x) (int)(x.size())
#define ms(x, y) memset(x, y, sizeof(x))
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
int k, n, m, dist[2001][201], A, B, ans = INF;
vector<piii> adj[2001];
priority_queue<piii, vector<piii>, greater<piii>> pq;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> k >> n >> m;
    for (int i = 0, a, b, t, h; i < m; i++){
        cin >> a >> b >> t >> h;
        adj[a].pb(mp(t, mp(b, h))); adj[b].pb(mp(t, mp(a, h)));
    }
    cin >> A >> B;
    ms(dist, INF); dist[A][0] = 0;
    pq.push(mp(0, mp(A, 0)));
    while(!pq.empty()){
        int u = pq.top().s.f, h = pq.top().s.s; pq.pop();
        for (auto v : adj[u]){
            if (v.s.s + h < k && dist[v.s.f][v.s.s + h] > dist[u][h] + v.f){
                dist[v.s.f][v.s.s + h] = dist[u][h] + v.f;
                pq.push(mp(dist[v.s.f][v.s.s + h], mp(v.s.f, h + v.s.s)));
            }
        }
    }
    for (int e : dist[B]) ans = min(ans, e);
    if (ans != INF) cout << ans;
    else cout << -1;
    return 0;
}