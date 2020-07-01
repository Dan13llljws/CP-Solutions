#include <bits/stdc++.h>
using namespace std;
#define gl(x) getline(cin, (x))
#define sz(x) (int)(x.size())
#define ms(x, y) memset(x, y, sizeof(x))
#define pb push_back
#define nl '\n'
int n, t; bool vis[100000];
string link, l, link2; vector<int> adj[100000]; queue<int> q; map<string, int> dict;
void bfs (int src){
    ms(vis, 0); q.push(src), vis[src] = 1;
    while(!q.empty()){
        int p = q.front(); q.pop();
        for (int v : adj[p])
            if (!vis[v]) vis[v] = 1, q.push(v);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n; cin.ignore();
    while(n--){
        gl(link);
        if (!dict.count(link)) dict[link] = ++t;
        while(gl(l) && l != "</HTML>"){
            bool flag = 0;
            for (int i = 0; i < sz(l); i++){
                if (l.substr(i, 6) == "A HREF") flag = 1, i += 8;
                if (l[i] == '\"'){
                    flag = 0;
                    if (!dict.count(link2)) dict[link2] = ++t;
                    adj[dict[link]].pb(dict[link2]);
                    cout << "Link from " << link << " to " << link2 << nl;
                    link2 = "";
                }
                if (flag) link2 += l[i];
            }
        }
    }
    gl(link);
    while(link != "The End"){
        gl(link2); bfs(dict[link]);
        if (vis[dict[link2]]) cout << "Can surf from " << link << " to " << link2 << '.' << nl;
        else cout << "Can't surf from " << link << " to " << link2 << '.' << nl;
        gl(link);
    }
    return 0;
}
