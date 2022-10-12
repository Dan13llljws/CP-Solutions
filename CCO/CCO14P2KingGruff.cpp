#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define ms(x, y) memset(x, y, sizeof(x))
#define flood(x) ms(x, 0x3f)
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
const int MOD = 1e9 + 7;
void add_self(int& a, int b){a+=b;if(a>=MOD)a-=MOD;}
void max_self(int& a, int b){a=max(a,b);}
void min_self(int& a, int b){a=min(a,b);}
long long gcd(long long a, long long b){return b==0?a:gcd(b,a%b);}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int , pii> ipi;
typedef pair<pii, pii> ppi;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
const int MM = 1e5 + 5;
struct edge{
    int a, b, w, c;
};
int N, M, A, B, Q, D, dist[2][MM];
vector<pii> adj1[MM], adj2[MM], paths; vector<edge> edges; vector<int> edgesum(MM);
bool cmp(pii a, pii b){return a.first < b.first;}
void dijkstra(int src, int dist[], vector<pii> adj[]){
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[src] = 0; q.push(mp(0, src));
    while(!q.empty()){
        int d = q.top().f, p = q.top().s; q.pop();
        if (d > dist[p]) continue;
        for (auto v : adj[p]){
            if (dist[v.f] > dist[p] + v.s){
                dist[v.f] = dist[p] + v.s;
                q.push(mp(dist[v.f], v.f));
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, M, A, B);
    for (int i = 0, x, y, l, c; i< M; i++){
        sc(x, y, l, c);
        adj1[x].pb(mp(y, l)); adj2[y].pb(mp(x, l));
        edges.pb({x, y, l, c});
    }
    ms(dist, INF);
    dijkstra(A, dist[0], adj1); dijkstra(B, dist[1], adj2);
    for (auto e : edges){ // find what is the length of the path that includes this edge
        int d1 = dist[0][e.a], d2 = dist[1][e.b];
        if (d1 == INF || d2 == INF) continue;
        paths.pb(mp(d1 + d2 + e.w, e.c)); // length, cost
    }
    paths.pb(mp(0, 0));
    sort(af(paths), cmp); // sort, every path represent one path: the length of the path its in, the cost to shut down the edge
    for (int i = 1; i <= M; i++) edgesum[i] = paths[i].s + edgesum[i - 1];
    sc(Q);
    while(Q--){
        sc(D);
        int l = 0, r = sz(paths) - 1, ans;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if (paths[mid].f <= D){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        pr(edgesum[ans], nl);
    }
    return 0;
}
