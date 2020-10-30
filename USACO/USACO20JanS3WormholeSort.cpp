#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define LL_INF 0x3f3f3f3f3f3f3f3f
#define sp ' '
#define nl '\n'
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
struct edge{
    int a, b, w;
} edges[100001];
int n, m, pos[100001], l = INF, r, mid, ans = -1, dsu[100001];
int Find(int x){
    return dsu[x] == x ? x : dsu[x] = Find(dsu[x]);
}
void unite(int x, int y){
    dsu[Find(x)] = Find(y);
}
bool check(int x){
    bool sorted = 0;
    for (int i = 1; i <= n; i++) dsu[i] = i;    
    for (int i = 0; i < m; i++){
        if (edges[i].w >= x) unite(edges[i].a, edges[i].b);
    }
    for (int i = 1; i <= n; i++){
        if (pos[i] != i){
            if (Find(i) != Find(pos[i])) return 0;
            else sorted = 1;
        }
    }
    return sorted;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(n, m);
    for (int i = 1; i <= n; i++) sc(pos[i]);
    for (int i = 0; i < m; i++){
        sc(edges[i].a, edges[i].b, edges[i].w);
        r = max(r, edges[i].w); l = min(l, edges[i].w);
    }
    while(l <= r){
        mid = l + (r - l) / 2;
        if (check(mid)){
            ans = mid; l = mid + 1;
        }
        else r = mid - 1;
    }
    pr(ans);
    return 0;
}
