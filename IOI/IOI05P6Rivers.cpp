#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int n, k, d[MM], w[MM], v[MM], dp[MM][MM][55]; vector<pair<int,int>> adj[MM];
int dfs (int src){
    dp[src][src][src > 0] = 0; int ret = 1;
    for (int i = v[src], sd = d[src]; i != -1; i = v[i])
        dp[src][i][0] = sd * w[src], sd += d[i];
    for (auto [wt, to] : adj[src]){
        ret += dfs(to);
        for (int i = src; i != -1; i = v[i])
            for (int i1 = min(k, ret); i1 >= 0; i1--){
                int tmp = 1e9;
                for (int j = 0; j <= i1; j++)
                    tmp = min(tmp, dp[src][i][i1 - j] + min(dp[to][i][j], dp[to][to][j]));
                dp[src][i][i1] = tmp;
            }
    } return ret;
}
int main(){
    scanf("%d%d", &n, &k), memset(dp, 0x3f, sizeof dp), v[0] = -1;
    for (int i = 1; i <= n; i++) 
        scanf("%d%d%d", w + i, v + i, d + i), adj[v[i]].push_back({d[i], i});
    dfs(0), printf("%d\n", dp[0][0][k]);
}
