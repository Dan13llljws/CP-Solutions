#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b), adj[b].push_back(a);
    } 
    vector<int> leaf;
    function<void(int,int)> dfs = [&](int src, int par){
        if ((int)adj[src].size() == 1) leaf.push_back(src);
        for (int v : adj[src])
            if (v != par) dfs(v, src);
    };
    dfs(1, 0);
    int k = leaf.size();
    cout << (k + 1) / 2 << '\n';
    for (int i = 0; i < (k + 1) / 2; i++)
        cout << leaf[i] << ' ' << leaf[(i + (k + 1) / 2) % k] << '\n';
}

