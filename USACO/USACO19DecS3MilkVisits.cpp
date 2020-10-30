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
#define pb push_back
int N, M, a, b, part[100010], p;
string s; char typ;
vector<int> adj[100010];
void dfs(int src, int par){
    if (part[src]) return;
    part[src] = p;
    for (int v : adj[src]){
        if (v != par && s[v - 1] == s[src - 1]) dfs(v, src);
    }
}
int main(){ 
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    sc(N, M, s);
    for (int i = 0; i < N - 1; i++){
        sc(a, b);
        adj[a].pb(b); adj[b].pb(a);
    }   
    for (int i = 1; i <= N; i++){ // instead of checking if a point is on the path
        if (!part[i]){            // just check if the two points are on a path full of the other type of cows
            p++;
            dfs(i, 0);
        }
    }
    for (int i = 0; i < M; i++){
        sc(a, b, typ);
        pr(s[a - 1] == typ || part[a] != part[b]);
    }
    return 0;
}
