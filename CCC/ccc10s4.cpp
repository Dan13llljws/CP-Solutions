#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
struct edge{int a, b, w;};
int n, e, w, dsu[101], maxe, ans1, ans2;
pii edgemtx[1001][1001]; vector<edge> edges;
bool cmp(edge a, edge b){return a.w < b.w;}
void init(){for (int i = 1; i <= n; i++) dsu[i] = i;}
int Find(int x){
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int x, int y){
    dsu[Find(x)] = Find(y);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n); init();
    for (int i = 1; i <= n; i++){
        sc(e); vector<int> es(e); 
        for (int j = 0; j < e; j++) sc(es[j]);
        es.pb(es[0]);
        for (int j = 0; j < e; j++){
            sc(w); maxe = max(maxe, es[j]);
            if (!edgemtx[es[j]][es[j + 1]].f){
                edgemtx[es[j]][es[j + 1]].f = i;
                edgemtx[es[j]][es[j + 1]].s = w;
                edgemtx[es[j + 1]][es[j]].f = i;
                edgemtx[es[j + 1]][es[j]].s = w;
            }
            else {
                edges.pb({i, edgemtx[es[j]][es[j + 1]].f, w});
                edgemtx[es[j]][es[j + 1]].f = 0;
                edgemtx[es[j]][es[j + 1]].s = 0;
                edgemtx[es[j + 1]][es[j]].f = 0;
                edgemtx[es[j + 1]][es[j]].s = 0;
            }
        }
    }
    for (int i = 1; i <= maxe; i++){
        for (int j = 1; j <= maxe; j++){
            if (edgemtx[i][j].f) edges.pb({edgemtx[i][j].f, 0, edgemtx[i][j].s});
        }
    }
    sort(af(edges), cmp);
    for (auto v : edges){
        if (Find(v.a) != Find(v.b)){
            unite(v.a, v.b);
            ans1 += v.w;
        }
    }
    init();
    for (auto v : edges){
        if (v.b == 0) continue;
        if (Find(v.a) != Find(v.b)){
            unite(v.a, v.b);
            ans2 += v.w;
        }
    }
    pr(min(ans1, ans2));
    return 0;
}