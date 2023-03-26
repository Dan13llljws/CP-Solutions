#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
#define nl '\n'
char _;
typedef pair<int, int> pii;
typedef long long ll;
const int M = 1e6 + 1;
int n, m, p, q;
vector<int> st[M];
queue<int> t;
bool vis[M];
bool bfs(int p, int q){
    vis[p] = 1;
    t.push(p);
    while(!t.empty()){
        int c = t.front();
        t.pop();
        if (c == q) return 1;
        for (int u : st[c]){
            if (!vis[u]){
                vis[u] = 1;
                t.push(u);
            }
        }
    }
    return 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        st[x].pb(y);
    }
    cin >> p >> q;
    if (bfs(p, q)) cout << "yes" << nl;
    else {
        memset(vis, 0, sizeof(vis));
        if (bfs(q, p)) cout << "no" << nl;
        else cout << "unknown" << nl;
    }
    return 0;
}