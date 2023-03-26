#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, x, y, dp[10000];
vector<int> adj[10000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    dp[1] = 1;
    while(1){
        cin >> x >> y;
        if (!x) break;
        adj[x].pb(y);
    }
    for (int i = 1; i < n; i++){
        for (int v : adj[i]){
            dp[v] += dp[i];
        }
    }
    cout << dp[n];
    return 0;
}