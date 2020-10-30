#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define pb push_back
int n, in[8], t, cur; string s1, s2, garbage, name[8]; bool vis[8];
map<string, int> dict;
vector<int> adj[8];
void dfs(int src){
    vis[src] = 1;
    cout << name[src] << nl;
    for (int v : adj[src]){
        if (!vis[v]) dfs(v);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin); freopen("", "w", stdout);
    cin >> n;
    //Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue.
    dict["Bessie"] = 3; dict["Buttercup"] = 6; dict["Belinda"] = 1;
    dict["Beatrice"] = 0; dict["Bella"] = 2; dict["Blue"] = 5;
    dict["Betsy"] = 4; dict["Sue"] = 7;
    name[0] = "Beatrice"; name[1] = "Belinda"; name[2] = "Bella"; name[3] = "Bessie";
    name[4] = "Betsy"; name[5] = "Blue"; name[6] = "Buttercup"; name[7] = "Sue";
    for (int i = 0; i < n; i++){
        cin >> s1; for (int j = 0; j < 4; j++) cin >> garbage; cin >> s2;
        adj[dict[s1]].pb(dict[s2]); adj[dict[s2]].pb(dict[s1]);
        in[dict[s1]]++; in[dict[s2]]++;
    }
    for (int i = 0; i < 8; i++){
        if (!vis[i] && in[i] <= 1) dfs(i);
    }
    return 0;
}
