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
int n, m, d, dsu[100001], ans, tot, maxw, e; 
vector<ppi> edges;
bool cmp(ppi a, ppi b){
    if(a.s.f == b.s.f) return a.s.s < b.s.s;
    return a.s.f < b.s.f;
}
int Find(int x){
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int x, int y){
    dsu[x] = y;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, m, d);
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1, a, b, c; i <= m; i++){
        sc(a, b, c);
        if (i < n) edges.pb(mp(mp(a, b), mp(c, 0)));
        else edges.pb(mp(mp(a, b), mp(c, 1)));
    }
    sort(af(edges), cmp);
    for (auto v : edges){
        if (tot == n - 1) break;
        int x = Find(v.f.f), y = Find(v.f.s);
        if (x != y){
            unite(x, y);
            tot++; maxw = v.s.f;
            if (v.s.s) ans++;
        }
        e++;
    }
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (auto v : edges){
        int x = Find(v.f.f), y = Find(v.f.s);
        if (x != y){
            if (v.s.f < maxw || (v.s.f == maxw && !v.s.s)) unite(x, y);
            else if (!v.s.s && v.s.f <= d){
                pr(ans - 1); return 0;
            }
        }
    }
    pr(ans);
    return 0;
}
