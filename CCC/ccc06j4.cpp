#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x.size())
#define af(x) x.begin(), x.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define nl '\n'
int root, x, y, in[8]; bool vis[8];
vector<int> adj[8], out; queue<int> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    adj[1].pb(7); adj[1].pb(4); adj[2].pb(1);
    adj[3].pb(4); adj[3].pb(5);
    in[7] = 1; in[4] = 2; in[1] = 1; in[5] = 1;
    while(cin >> x >> y && x != 0 && y != 0){
        adj[x].pb(y); in[y]++;
    }
    for (int i = 1; i < 8; i++){
        if(!in[i]){
            q.push(i);
            vis[i] = 1;
            break;
        }
    }
    while(!q.empty()){
        int p = q.front(); q.pop(); out.pb(p);
        vis[p] = 1;
        for(int v : adj[p]) in[v]--;
        for (int i = 1; i < 8; i++){
            if(!in[i] && !vis[i]){
                q.push(i);
                vis[i] = 1;
                break;
            }
        }
    }
    for (int i = 1; i < 8; i++){
        if (in[i] >0){
            cout << "Cannot complete these tasks. Going to bed." << nl;
            return 0;
        }
    }
    for (int u : out) cout << u << ' ';
    return 0;
}