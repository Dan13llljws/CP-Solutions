#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define INF 0x3f3f3f3f
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define nl '\n'
char _;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
int n, t, k, d, dist[5001], adj[5001][5001], ans = INF; bool vis[5001];
vector<pii> sale;
int minIndex(){
    int m = INF, index;
    for (int i = 1; i <= n; i++){
        if (dist[i] < m && !vis[i]){
            m = dist[i];
            index = i;
        }
    }
    return index;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n); scan(t);
    ms(adj, INF);
    for (int i = 0, x, y, z; i < t; i++){
        scan(x); scan(y); scan(z);
        adj[x][y] = min(adj[x][y], z); adj[y][x] = min(adj[y][x], z);
    }
    scan(k);
    for (int i = 0, x, y; i < k; i++){
        scan(x); scan(y);
        sale.pb(mp(x, y));
    }
    scan(d);
    ms(dist, INF); dist[d] = 0;
    for (int i = 1; i < n; i++){
        int u = minIndex();
        vis[u] = 1;
        for (int v = 1; v <= n; v++){
            if (adj[u][v] && !vis[v] && dist[u] != INF && dist[v] > dist[u] + adj[u][v]){
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < sz(sale); i++){
        ans = min(dist[sale[i].f] + sale[i].s, ans);
    }
    cout << ans;
    return 0;
}