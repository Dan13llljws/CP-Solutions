#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
#define f first
#define s second
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;
int n, m, dsu[100001], sz[100001], ans = INF;
ppi corners[100001];
int Find(int x){
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int x, int y){
    int tmp = Find(y), i = Find(x);
    dsu[i] = tmp;
    corners[tmp].f.f = min(corners[tmp].f.f, corners[i].f.f);
    corners[tmp].f.s = max(corners[tmp].f.s, corners[i].f.s);
    corners[tmp].s.f = max(corners[tmp].s.f, corners[i].s.f);
    corners[tmp].s.s = min(corners[tmp].s.s, corners[i].s.s);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, m);
    for (int i = 1; i <= n; i++) dsu[i] = i;
    for (int i = 1, x, y; i <= n; i++){
        sc(corners[i].f.f, corners[i].f.s);
        corners[i].s.f = corners[i].f.f; corners[i].s.s = corners[i].f.s;
    }
    for (int i = 0, a, b; i < m; i++){
        sc(a, b); unite(a, b);
    }
    for (int i = 1; i <= n; i++){
        int tmp = Find(i);
        int s = corners[tmp].s.f - corners[tmp].f.f + corners[tmp].f.s - corners[tmp].s.s;
        ans = min(ans, s);
    }
    pr(ans * 2);
    return 0;
}
