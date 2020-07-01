#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define nl '\n'
typedef pair<int, int> pii;
bool vis[26];
string road; vector<int> adj[26]; vector<string> edge, ans; queue<int> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    while(cin >> road && road != "**"){
        adj[road[0] - 'A'].pb(road[1] - 'A');
        adj[road[1] - 'A'].pb(road[0] - 'A');
        edge.pb(road);
    }
    for (int i = 0; i < sz(edge); i++){
        int u = edge[i][0] - 'A', v = edge[i][1] - 'A';
        ms(vis, 0); q.push(u); vis[u] = 1;
        while(!q.empty()){
            int p = q.front(); q.pop();
            for (int w : adj[p])
                if (!vis[w] && !(p == u && w == v)) vis[w] = 1, q.push(w);
        }
        if (!vis[v]) ans.pb(edge[i]);
    }
    for (string s : ans) cout << s << nl;
    cout << "There are " << sz(ans) << " disconnecting roads." << nl;
}
