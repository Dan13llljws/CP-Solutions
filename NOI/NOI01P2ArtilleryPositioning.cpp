#include <bits/stdc++.h>
using namespace std;
int n, m, tot, cur, pre, ans, pos[65], h[104], dp[2][65][65]; char g[10];
int main(){
    scanf("%d%d", &n, &m); pre = 1;
    for (int i = 1; i <= n; i++){
        scanf("%s", g);
        for (int j = 0; j < m; j++)
            if (g[j] == 'H') h[i] |= 1 << j;
    }
    for (int i = 0; i < (1 << m); i++)
        if (!(i & (i << 1) || i & (i << 2))) pos[tot++] = i;
    for (int i = 1; i <= n; i++, cur ^= 1, pre ^= 1){
        memset(dp[cur], 0, sizeof dp[cur]);
        for (int j = 0; j < tot; j++)
            for (int k = 0; k < tot; k++){
                if (pos[k] & pos[j]) continue;
                for (int l = 0; l < tot; l++){
                    if (pos[l] & h[i] || pos[l] & pos[j] || pos[l] & pos[k]) continue;
                    dp[cur][k][l] = max(dp[cur][k][l], dp[pre][j][k] + __builtin_popcount(pos[l]));
                    ans = max(ans, dp[cur][k][l]);
                }
            }
    } printf("%d\n", ans);
}
